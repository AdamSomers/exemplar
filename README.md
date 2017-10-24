# exemplar

When building any software, the author should strive to write the software as a set of reusable components. 
This is most readily achieved when the components are organized as independent libraries that can be debugged 
and tested in isolation. This project serves to demonstrate a clean way of doing this using cmake and googletest.

Build with these commands (on MacOS / linux)
```mkdir build
cd build
cmake ..
cmake --build .
ctest
./exemplarapp
```
... Or equivalent commands in cmd.exe, Visual Studio, VS Code, CLion, etc.

There are three primary targets in the build script:
1. exemplarlib: a target that compiles all code as a static library that can be linked to other targets
2. exemplarapp: an executable that runs example functions for use with a debugger
3. runUnitTests: a googletest runner that runs the unit tests.

The examples are not intended to be complete, but to serve as a starting point for anyone who endeavors to
* set up a build system with CMake
* add unit tests to their code
* create a modular class library
* study algorithms & data structures
