use linux like system please

use `sudo apt-get install g++` to set up environment.

choose your favorite editor and other tools like debug tools.

then let's compile it and run
```
# compile to binary
g++ helloworld.cpp -o hello.o

# compile to assembler code
g++ helloworld.cpp -s hello.s

# make assembler code to binary
g++ hello.s -o hello.o

# run
./hello.o
```