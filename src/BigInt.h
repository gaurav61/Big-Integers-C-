#ifndef BigInt_H
#define BigInt_H
#include<string>
using namespace std;
class BigInt{

    string var;

    public:
        BigInt(string x);
        BigInt add(BigInt obj);
        BigInt sub(BigInt obj);
        BigInt mul(BigInt obj);
        string getVal();
        void operator = (string x);
        BigInt operator + (BigInt const &obj);
        BigInt operator - (BigInt const &obj);
        BigInt operator * (BigInt const &obj);
        static bool isSmaller(string x , string y);
        static string subHelper(string x , string y);
        static string mulHelper(string x , string y);
        static bool allZeroes(string x);
        friend ostream& operator<<(ostream& os, BigInt const &obj);
};

#endif