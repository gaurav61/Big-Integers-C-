#include<iostream>
#include "BigInt.h"

using namespace std;

int main(){
	string a,b;
	long long int c;
	cin>>a>>b;
	cin>>c;
	int d;
	cin>>d;
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
	cout<<obj.div(c).getVal()<<endl;
	cout<<obj/c<<endl;
	BigInt obj6 = obj2.abs();
	cout<<obj6<<endl;
	BigInt obj7 = -obj6;
	cout<<obj7<<endl;
	cout<<BigInt::fact(d)<<endl;
	return 0;
}
