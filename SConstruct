# File: SConstruct
# Author: Alex Sylvanus

#import methods
#import sys

# Define the source files
src_files = ['main.c', 'src/adate.c', 'src/astring.c', 'src/avector.c', 'src/vectorTest.c']

# Define the include directory
inc_dir = ['./inc']

# Define the environment
env = Environment(CPPPATH = inc_dir)

# Compile the program
env.Program('Test', src_files)