#include<iostream>
#include "BigInt.h"

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	BigInt obj(a);
	BigInt obj2(b);
	BigInt obj3 = a;
	BigInt obj4 = b;
	BigInt obj5 = obj3 + obj4;
	cout<<obj.add(obj2).getVal()<<endl;
	cout<<obj3.add(obj4).getVal()<<endl;
	cout<<obj5.getVal()<<endl;
	return 0;
}
