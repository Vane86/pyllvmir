import ctypes


lib = ctypes.CDLL("./libmodule.so")

lib.parseIRFile_wrap.argtypes = [ctypes.c_char_p]
lib.parseIRFile_wrap.restype = ctypes.c_void_p


class ModulePtr:
    def __init__(self, ptr):
        self._ptr = ptr
    
    def get_ptr():
        return self._ptr
        

def init():
    lib.init()
    

def clear():
    lib.clear()


def parseIRFile(file_path):
    module_ptr = lib.parseIRFile_wrap(file_path.encode('utf-8'))
    return ModulePtr(module_ptr)

