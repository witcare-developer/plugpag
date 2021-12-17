from _my_print import ffi, lib

def main(argv):
    lib.print_person(34, b"Renato")
    return 0

if __name__ == "__main__":
    import sys
    sys.exit(main(sys.argv))