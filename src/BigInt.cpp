
#include "BigInt.h"
#include <algorithm>
#include <iostream>

BigInt::BigInt(string x){
	this->var = x;
}

BigInt BigInt::add(BigInt obj){
	string ans;
	string x = obj.var;
	string y = this->var;
	int l1 = x.length();
	int l2 = y.length();
	int carry = 0;
	while(l1>0 && l2>0){
		int sum = (x[l1-1] - '0') + (y[l2-1] - '0') + carry;
		ans.push_back(sum%10 + '0');
		carry = sum/10;
		l1--;
		l2--;
	}
	while(l1>0){
		int sum = (x[l1-1] - '0') + carry;
		ans.push_back(sum%10 + '0');
		carry = sum/10;
		l1--;
	}
	while(l2>0){
		int sum = (y[l2-1] - '0') + carry;
		ans.push_back(sum%10 + '0');
		carry = sum/10;
		l2--;
	}
	if(carry>0){
		ans.push_back(carry + '0');
	}
	reverse(ans.begin(),ans.end());
	return *(new BigInt(ans));
}
string BigInt::getVal(){
	return this->var;
}

void BigInt::operator = (string x){
	this->var = x;
}

BigInt BigInt::operator + (BigInt const &obj){
	return this->add(obj);
}