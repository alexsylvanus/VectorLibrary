# File: SConstruct
# Author: Alex Sylvanus

#import methods
#import sys

# Define the source files
src_dir = 'src'
src_files = ['main.c'] + Glob('%s/*.c'%(src_dir))

# Define the include directory
inc_dir = ['#./inc']

# Define the environment
env = Environment(CPPPATH = inc_dir)

# Define directory for build files
SConscript(['src/SConscript'], exports='env', variant_dir='build', duplicate=0)


print(env.Dump())
# Compile the program
# env.Program('Test', 'main.c', LIBS=['VectorLib'], LIBPATH='build')