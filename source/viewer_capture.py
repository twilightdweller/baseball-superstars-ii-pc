"""Capture the viewer's client area at its native resolution for pixel checks."""
import ctypes as C
from ctypes import wintypes as W
import struct

from PIL import Image

ui = C.WinDLL('user32', use_last_error=True)
gdi = C.WinDLL('gdi32', use_last_error=True)
ui.GetWindowRect.argtypes = ui.GetClientRect.argtypes = [W.HWND, C.POINTER(W.RECT)]
ui.SetWindowPos.argtypes = [W.HWND, W.HWND, C.c_int, C.c_int, C.c_int, C.c_int, W.UINT]
ui.PrintWindow.argtypes = [W.HWND, W.HDC, W.UINT]
gdi.CreateCompatibleDC.argtypes = [W.HDC]
gdi.CreateCompatibleDC.restype = W.HDC
gdi.CreateDIBSection.argtypes = [W.HDC, C.c_void_p, W.UINT, C.POINTER(C.c_void_p), W.HANDLE, W.DWORD]
gdi.CreateDIBSection.restype = W.HBITMAP
gdi.SelectObject.argtypes = [W.HDC, W.HANDLE]
gdi.SelectObject.restype = W.HANDLE
gdi.DeleteDC.argtypes = [W.HDC]
gdi.DeleteObject.argtypes = [W.HANDLE]


def capture(hwnd):
    width, height = 480, 320
    outer, client = W.RECT(), W.RECT()
    assert ui.GetWindowRect(hwnd, C.byref(outer)) and ui.GetClientRect(hwnd, C.byref(client))
    assert ui.SetWindowPos(hwnd, None, 0, 0, width + outer.right - outer.left - client.right,
                           height + outer.bottom - outer.top - client.bottom, 0x16)
    assert ui.GetClientRect(hwnd, C.byref(client)) and (client.right, client.bottom) == (width, height)
    dc = gdi.CreateCompatibleDC(None)
    assert dc
    bits = C.c_void_p()
    header = struct.pack('<IiiHHIIiiII', 40, width, -height, 1, 32, 0, 0, 0, 0, 0, 0)
    bitmap = gdi.CreateDIBSection(dc, header, 0, C.byref(bits), None, 0)
    previous = None
    try:
        assert bitmap and bits.value
        previous = gdi.SelectObject(dc, bitmap)
        assert previous
        assert ui.PrintWindow(hwnd, dc, 1), C.get_last_error()
        gdi.GdiFlush()
        return Image.frombytes('RGB', (width, height), C.string_at(bits, width*height*4), 'raw', 'BGRX')
    finally:
        if previous:
            gdi.SelectObject(dc, previous)
        if bitmap:
            gdi.DeleteObject(bitmap)
        gdi.DeleteDC(dc)
