from distutils.core import setup, Extension
MOD = "benchmark"
setup(name = MOD, ext_modules = [Extension(MOD,sources=['bench_mark.c'])],
description = "My C Extension Module")
