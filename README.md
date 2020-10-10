# Dynamic linked library for handling Big Integers in C++

## Prerequisite
* GCC compiler (C++11 / C++14 / C++17).

## Build from the Source Code
* Clone the repository using :-
    ```
    $ git clone https://github.com/gaurav61/Big-Integers-C-.git
    ```
* Move inside the src folder.

* To start we need to create the object file first :-
    ```
    $ g++ -fPIC -c BigInt.cpp
    ```
* we created the object file with the ``-fPIC`` flag. This flag stands for Position Independent Code, a characteristic required by shared libraries.

* Next create the dynamic linked library from the object file generated in the previous step :- 
    ```
    $ g++ -shared -o ../lib/libBigInt.so BigInt.o
    ```
* The ``-shared`` key tells the compiler to produce a shared object which can then be linked with other objects to form an executable. ``libBigInt.so`` is the shared library and we are storing it under the ``lib`` directory of the repository.

## Usage
* Copy the ``BigInt.h`` file present in the src directory and paste it in the directory where your cpp program is present.

* Simply include the ``BigInt.h`` in your cpp program by :-
    ```
    #include "BigInt.h"
    ```

* Set the environment variable ``LD_LIBRARY_PATH`` to the directory where ``libBigInt.so`` is present.
    ```
    export LD_LIBRARY_PATH=<Path to the directory where libBigInt.so is Present>:$LD_LIBRARY_PATH
    ```
* The environment variable ``LD_LIBRARY_PATH`` is used to dynamically link the shared library at run time.

* Compile your source code with the following command :-
    ```
    g++ your_code.cpp -L<Path to the directory where libBigInt.so is present> -lBigInt -o your_code
    ```

* where -L flag specifies the path to the library and -l flag specifies the name of the library to use. Please note that we didn’t provide the lib prefix, as well as the .so extension: they were resolved by the compiler.

* Run your code using :-
    ```
    ./your_code
    ```

## Features
### Object Creation
* #### Using constructor
  ```
  string a;
  cin>>a;
  BigInt obj1(a);
  ```
* #### Using assignment operator
  ```
  string a,b;
  cin>>a>>b;
  BigInt obj1 = a;
  BigInt obj2;
  obj2 = b;
  ```
