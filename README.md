# Dynamic linked library for handling Big Integers in C++

## Prerequisite
* GCC compiler (C++11 / C++14 / C++17).

## Build from the Source Code
* Clone the repository using :-
    ```
    $ git clone https://github.com/gaurav61/Big-Integers-C-.git
    ```
* Move inside the lib folder.

* Run the Makefile, based on your platform it will generate libBigInt.so(if you are on Linux) or BigInt.dll(if you are on Windows).
    ```
    $ make
    ```

* When we run the Makefile, it first creates the object file using :-
    ```
    $ g++ -fPIC -c BigInt.cpp
    ```
* The object file is created with the ``-fPIC`` flag. This flag stands for Position Independent Code, a characteristic required by shared libraries.

* Next Makefile will create the dynamic linked library(.so if you are on linux and .dll if you are on windows) from the object file generated in the previous step :- 
    ```
    $ g++ -shared -o libBigInt.so BigInt.o
    ```
    or 

    ```
    $ g++ -shared -o BigInt.dll BigInt.o
    ```
* The ``-shared`` key tells the compiler to produce a shared object which can then be linked with other objects to form an executable.

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
  cout<<obj2; // 100162146527324082834222
  cout<<obj3; // 100162146527324082834222
  ```

### Other operations
* #### Absolute
  ```
  string a;
  cin>>a; // a = -765431976424211928288190282624167828
  BigInt obj1 = a;
  BigInt obj2 = obj1.abs();
  cout<<obj1; // -765431976424211928288190282624167828
  cout<<obj2; // +765431976424211928288190282624167828
  ```
* #### Negative unary
  ```
  string a;
  cin>>a; // a = 765431976424211928288190282624167828
  BigInt obj1 = a;
  BigInt obj2 = -obj1;
  cout<<obj1; // 765431976424211928288190282624167828
  cout<<obj2; // -765431976424211928288190282624167828
  ```

* #### Initialization
  ```
  string a;
  cin>>a; // a = 765431976424211928288190282624167828
  BigInt obj1 = a;
  BigInt obj2 = obj1;
  cout<<obj1; // 765431976424211928288190282624167828
  cout<<obj2; // 765431976424211928288190282624167828
  ```

* #### Factorial
  ```
  int a;
  cin>>a; // a = 50
  BigInt obj1 = BigInt::fact(a);
  cout<<obj1; // 30414093201713378043612608166064768844377641568960512000000000000
  ```


* #### Mod
  ```
  string a;
  long long int b;
  cin>>a>>b; // a = 30414093201713378043612608166064768844377641568960512000000000000 , b = 1000000007
  BigInt obj1 = a;
  BigInt obj2 = obj1%b;
  BigInt obj3 = obj1.mod(b);
  cout<<obj2; // 318608048
  cout<<obj3; // 318608048
  ```

* #### Power
  ```
  string a;
  int b;
  cin>>a>>b; // a = 78, b = 5
  BigInt obj1 = BigInt::pow(a,b);
  cout<<obj1; // 2887174368
  ```