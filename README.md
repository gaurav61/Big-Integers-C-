# Dynamic linked library for handling Big Integers in C++

## Prerequisite
* GCC compiler (C++11 / C++14 / C++17).

## Build from the Source Code
1. Clone the repository using :-
```
$ git clone https://github.com/gaurav61/Big-Integers-C-.git
```
2. Move inside the src folder.

3. To start we need to create the object file first with command :-
```
$ g++ -fPIC -c BigInt.cpp
```
* we created the object file with the ``-fPIC`` flag. This flag stands for Position Independent Code, a characteristic required by shared libraries.

4. Next create the dynamic linked library from the object file generated in the previous step :- 
```
$ g++ -shared -o ../lib/libBigInt.so *.o
```
* The ``-shared`` key tells the compiler to produce a shared object which can then be linked with other objects to form an executable. ``libBigInt.so`` is the shared library and we are storing it under the ``lib`` directory of the repository.
