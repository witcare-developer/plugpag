from cffi import FFI

ffi  = FFI()

ffi.cdef(""" void print_person(int n, char* m); """)
ffi.set_source("_my_print",
"""
void print_person(int n, char* m);
""",
sources=['cffi_teste.c'],
library_dirs = []
)

if __name__ == "__main__":
    ffi.compile(verbose=True)