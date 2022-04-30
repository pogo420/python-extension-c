from distutils.core import setup, Extension


# entry point of module
def main():
    setup(name="fputs",
          version="1.0.0",
          description="Python interface for the fputs C library function",
          author="Arnab",
          author_email="your_email@gmail.com",
          ext_modules=[Extension("fputs", ["fputsmodule.c"])])


if __name__ == "__main__":
    main()

