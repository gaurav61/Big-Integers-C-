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
### Arithmetic operations
* #### Addition
  ```
  string a,b;
  cin>>a>>b; // a=764524274758362354757437827843 , b=2837462637483927476483294757
  BigInt obj1 = a;
  BigInt obj2 = b;
  BigInt obj3 = obj1+obj2;
  BigInt obj4 = obj1.add(obj2);
  cout<<obj3; // 767361737395846282233921122600
  cout<<obj4; // 767361737395846282233921122600
  ```

* #### Subtraction
  ```
  string a,b;
  cin>>a>>b; // a=764524274758362354757437827843 , b=2837462637483927476483294757
  BigInt obj1 = a;
  BigInt obj2 = b;
  BigInt obj3 = obj1-obj2;
  BigInt obj4 = obj1.sub(obj2);
  cout<<obj3; // 761686812120878427280954533086
  cout<<obj4; // 761686812120878427280954533086
  ```

  * #### Multliplication
  ```
  string a,b;
  cin>>a>>b; // a=764524274758362354757437827843 , b=2837462637483927476483294757
  BigInt obj1 = a;
  BigInt obj2 = b;
  BigInt obj3 = obj1*obj2;
  BigInt obj4 = obj1.mul(obj2);
  cout<<obj3; // 2169309065076349687925604412176078250206429223217990519151
  cout<<obj4; // 2169309065076349687925604412176078250206429223217990519151
  ```

   * #### Division
  ```
  string a;
  long long int b;
  cin>>a>>b; // a=765431976424211928288190282624167828 , b=7641928642328
  BigInt obj1 = a;
  BigInt obj2 = obj1/b;
  BigInt obj3 = obj1.div(b);
  cout<<obj3; // 100162146527324082834222
  cout<<obj4; // 100162146527324082834222
  ```