#ifndef BigInt_H
#define BigInt_H
#include<string>
using namespace std;
class BigInt{

    string var;

    public:
        BigInt(string x);
        BigInt add(BigInt x);
        string getVal();
        void operator = (string x);
        BigInt operator + (BigInt const &obj);
};

#endif