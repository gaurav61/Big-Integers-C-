UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
TARGET = libBigInt.so
else
TARGET = BigInt.dll
endif

$(TARGET): BigInt.o
	g++ -shared -o libBigInt.so BigInt.o

BigInt.o: BigInt.cpp BigInt.h
	g++ -fPIC -c BigInt.cpp

clean:
	rm -f *.o *.so *.dll