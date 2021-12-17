from cffi import FFI

ffi = FFI()

ffi.cdef(""" void totem(char* porta, int metodoPag,int tipo_prestacao, int qtd_prestacao, char* valor, char* codigo_vendedor ); """)
ffi.set_source("_compilacao_pag",
"""
void totem(char* porta, int metodoPag,int tipo_prestacao, int qtd_prestacao, char* valor, char* codigo_vendedor );
""",
sources=['cffi_pagseguro.c'],
library_dirs = [],
libraries = ["libPPPagSeguro/PPPagSeguro.h"]
)

if __name__ == "__main__":
    ffi.compile(verbose=True)