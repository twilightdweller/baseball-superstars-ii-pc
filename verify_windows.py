"""Build the unchanged recovered C code and run the checkpoint tests on Windows.

Usage: python verify_windows.py [--apk PATH]
Requires VS C++ Build Tools, Windows SDK, pyelftools, unicorn and Pillow.
The APK and extracted ARM library are used only by development verification.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import zipfile

ROOT = Path(__file__).resolve().parent
SOURCE = ROOT / 'source'
BUILD = ROOT / 'build'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--apk', type=Path, default=ROOT / 'baseball-superstars-ii.apk')
    args = parser.parse_args()
    apk = args.apk.resolve()
    BUILD.mkdir(exist_ok=True)
    results = []
    env = os.environ.copy()
    env['BS2_TEST_LIB_DIR'] = str(BUILD)

    def run(label, command, cwd=SOURCE):
        result = subprocess.run(command, cwd=cwd, env=env, capture_output=True, text=True)
        output = result.stdout + result.stderr
        (BUILD / (label + '.log')).write_text(output, encoding='utf-8')
        results.append({'check': label, 'exit_code': result.returncode})
        print(f'{label}: {"PASS" if result.returncode == 0 else "FAIL"}')
        print(output[-3000:].rstrip(), flush=True)
        return result.returncode == 0

    vswhere = Path(os.environ.get('ProgramFiles(x86)', r'C:\Program Files (x86)')) / 'Microsoft Visual Studio/Installer/vswhere.exe'
    found = subprocess.check_output([str(vswhere), '-latest', '-products', '*', '-requires',
                                     'Microsoft.VisualStudio.Component.VC.Tools.x86.x64',
                                     '-property', 'installationPath'], text=True).strip()
    if not found:
        raise SystemExit('Visual Studio C++ build tools were not found.')
    vcvars = Path(found) / 'Common7/Tools/VsDevCmd.bat'
    common = ['cl', '/nologo', '/std:c11', '/O2', '/W4', '/WX', '/MT', '/Fo:' + str(BUILD) + '\\']

    def compile_target(name, sources, dll=False, gui=False):
        output = BUILD / (name + ('.dll' if dll else '.exe'))
        # Remove a previous output so a failed build cannot run a stale binary.
        output.unlink(missing_ok=True)
        command = common + (['/LD'] if dll else []) + sources + ['/Fe:' + str(output)]
        if gui:
            command += ['/link', 'gdi32.lib', 'user32.lib', '/SUBSYSTEM:WINDOWS']
        elif dll:
            exports = sorted(set(symbol for file in sources for symbol in
                                 re.findall(r'\b(bs2_\w+)\s*\(', (SOURCE / file).read_text())))
            command += ['/link'] + ['/EXPORT:' + name for name in exports]
        script = BUILD / ('compile-' + name + '.cmd')
        script.write_text('@echo off\ncall "' + str(vcvars) + '" -arch=x64 -host_arch=x64\n'
                          'if errorlevel 1 exit /b 1\n' + subprocess.list2cmdline(command) + '\n')
        return run('build-' + name, ['cmd.exe', '/d', '/c', str(script)])

    viewer = ['src/' + name + '.c' for name in
              ['pitch_viewer', 'pitch_path', 'pitch_curve', 'projection', 'pitch_scene', 'camera',
               'taken_pitch', 'pitch_rules', 'pitch_flow']]
    if compile_target('BS2-Pitch-Motion', viewer, gui=True):
        run('test-at-bat-viewer', [sys.executable, 'test_at_bat_viewer.py', str(BUILD / 'BS2-Pitch-Motion.exe')])
    libraries = {
        'currency': ['currency'], 'state': ['state'], 'title-flow': ['title_flow'],
        'graphics': ['graphics'], 'pitch-curve': ['pitch_curve'], 'projection': ['projection'],
        'pitch-path': ['pitch_path', 'pitch_curve', 'projection', 'pitch_scene'],
        'camera': ['camera', 'projection'],
        'pitch-rules': ['pitch_rules'],
        'pitch-flow': ['pitch_flow'],
        'taken-pitch': ['taken_pitch', 'pitch_rules', 'pitch_flow', 'pitch_scene', 'projection', 'camera', 'pitch_path', 'pitch_curve'],
    }
    for name, sources in libraries.items():
        compile_target('bs2-' + name, ['src/' + item + '.c' for item in sources], dll=True)
    if compile_target('test-menu', ['test_menu.c', 'src/menu.c']):
        run('test-menu', [str(BUILD / 'test-menu.exe')])

    with zipfile.ZipFile(apk) as archive:
        bad = archive.testzip()
        if bad:
            raise ValueError('APK CRC failed: ' + bad)
        original = BUILD / 'libgameDSO.so'
        original.write_bytes(archive.read('lib/armeabi/libgameDSO.so'))
    hashes = {str(p.relative_to(ROOT)) if p.is_relative_to(ROOT) else str(p):
              hashlib.sha256(p.read_bytes()).hexdigest() for p in [apk, original]}
    (BUILD / 'input-hashes.json').write_text(json.dumps(hashes, indent=2))
    run('extract-pitch', [sys.executable, 'extract_pitch.py', str(apk), str(BUILD / 'pitch-records.json')])
    same = json.loads((BUILD / 'pitch-records.json').read_text()) == json.loads((SOURCE / 'pitch-records.json').read_text())
    results.append({'check': 'pitch-fixture-equality', 'exit_code': 0 if same else 1})
    run('extract-figure', [sys.executable, 'extract_figure.py', str(apk), str(BUILD / 'figure-assets')])
    for fixture in (SOURCE / 'figure-assets').iterdir():
        same = fixture.read_bytes() == (BUILD / 'figure-assets' / fixture.name).read_bytes()
        results.append({'check': 'figure-fixture-' + fixture.name, 'exit_code': 0 if same else 1})

    tests = {
        'check_original': [str(original)], 'test_native': [str(original)],
        'test_state': [str(original)], 'test_title_flow': [str(original)],
        'test_startup_sequence': [], 'test_graphics': [str(original), str(apk)],
        'test_figure_selection': [str(original)],
    }
    for test, library in [('test_pitch_curve', 'pitch-curve'), ('test_cardinal', 'pitch-curve'),
                          ('test_projection', 'projection'), ('test_pitch_path', 'pitch-path'),
                          ('test_camera', 'camera'), ('test_pitch_rules', 'pitch-rules'),
                          ('test_pitch_flow', 'pitch-flow'), ('test_taken_pitch', 'taken-pitch')]:
        tests[test] = [str(original), str(BUILD / ('bs2-' + library + '.dll'))]
    for test, arguments in tests.items():
        run(test, [sys.executable, test + '.py', *arguments])
    (BUILD / 'results.json').write_text(json.dumps(results, indent=2))
    failures = [row['check'] for row in results if row['exit_code']]
    print('Failed checks: ' + ', '.join(failures) if failures else 'All checks passed.')
    return 1 if failures else 0


if __name__ == '__main__':
    sys.exit(main())
