#include<iostream>
#include "BigInt.h"

using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	BigInt obj(a);
	BigInt obj2(b);
	cout<<obj.add(obj2).getVal()<<endl;
	BigInt obj3 = obj + obj2;
	cout<<obj3.getVal()<<endl;
	cout<<obj.sub(obj2).getVal()<<endl;
	BigInt obj4 = obj - obj2;
	cout<<obj4.getVal()<<endl;
	BigInt obj5 = obj * obj2;
	cout<<obj5.getVal()<<endl;
	cout<<obj5<<endl;
	return 0;
}
