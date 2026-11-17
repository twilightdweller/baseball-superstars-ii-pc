"""Resolve host test libraries without changing the original comparison logic."""
import ctypes
import os
from pathlib import Path


def load(name):
    directory = os.environ.get('BS2_TEST_LIB_DIR')
    if directory:
        suffix = '.dll' if os.name == 'nt' else '.so'
        return ctypes.CDLL(str(Path(directory).resolve() / (name + suffix)))
    return ctypes.CDLL('/tmp/' + name + '.so')
