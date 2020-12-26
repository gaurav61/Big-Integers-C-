
#include "BigInt.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

BigInt::BigInt(){
	this->var = "0";
}

BigInt::BigInt(string x){
	this->var = x;
}

BigInt BigInt::add(BigInt obj){
	string ans;
	string x = this->var;
	string y = obj.var;
	if(x.find("inf")!=string::npos){
		return *this;
	}
	if(y.find("inf")!=string::npos){
		return obj;
	}
	int l1 = x.length();
	int l2 = y.length();
	bool x_sign = false;
	bool y_sign = false;
	if(x[0]=='-'){
		x_sign = true;
		string temp;
		for(int i = 1; i<l1 ; i++){
			temp.push_back(x[i]);
		}
		x = temp;
	}
	if(y[0]=='-'){
		y_sign = true;
		string temp;
		for(int i = 1; i<l2 ; i++){
			temp.push_back(y[i]);
		}
		y = temp;
	}
	if(x[0]=='+'){
		string temp;
		for(int i = 1; i<l1 ; i++){
			temp.push_back(x[i]);
		}
		x = temp;
	}
	if(y[0]=='+'){
		string temp;
		for(int i = 1; i<l2 ; i++){
			temp.push_back(y[i]);
		}
		y = temp;
	}
	if((x_sign==false && y_sign==false) || (x_sign==true && y_sign==true)){
	int carry = 0;
	l1 = x.length();
	l2 = y.length();
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
	if(x_sign==true && y_sign==true){
		ans.push_back('-');
	}
	reverse(ans.begin(),ans.end());
	return *(new BigInt(ans));
	}
	else{
		if(BigInt::isSmaller(x,y)){
			if(x_sign){
				string temp = BigInt::subHelper(y,x);
				if(BigInt::allZeroes(temp)){
					return *(new BigInt("0"));
				}
				return *(new BigInt(temp));
				// do y-x
			}
			else{
				string temp = BigInt::subHelper(y,x);
				if(BigInt::allZeroes(temp)){
					return *(new BigInt("0"));
				}
				string temp2 = "-";
				int temp_l = temp.length();
				for(int i = 0; i<temp_l; i++){
					temp2.push_back(temp[i]);
				}
				return *(new BigInt(temp2));
				// do -(y-x)
			}
		}
		else{
			if(x_sign){
				string temp = BigInt::subHelper(x,y);
				if(BigInt::allZeroes(temp)){
					return *(new BigInt("0"));
				}
				string temp2 = "-";
				int temp_l = temp.length();
				for(int i = 0; i<temp_l; i++){
					temp2.push_back(temp[i]);
				}
				return *(new BigInt(temp2));
				// -(x-y)
			}
			else{
				string temp = BigInt::subHelper(x,y);
				if(BigInt::allZeroes(temp)){
					return *(new BigInt("0"));
				}
				return *(new BigInt(temp));
				// (x-y)
			}
		}
	}
}

BigInt BigInt::sub(BigInt obj){
	string temp = obj.var;
	if(temp[0]=='-'){
		temp[0]='+';
		BigInt objTemp(temp);
		return this->add(objTemp);
	}
	else{
		if(temp[0]=='+'){
			temp[0]='-';
			BigInt objTemp(temp);
			return this->add(objTemp);
		}
		else{
			string temp2 = "-";
			int l = temp.length();
			for(int i = 0; i<l ; i++){
				temp2.push_back(temp[i]);
			}
			BigInt objTemp(temp2);
		    return this->add(objTemp);
		}
	}
}

BigInt BigInt::mul(BigInt obj){
	string ans;
	string x = this->var;
	string y = obj.var;
	if(x.find("inf")!=string::npos){
		return *this;
	}
	if(y.find("inf")!=string::npos){
		return obj;
	}
	bool x_sign = false;
	bool y_sign = false;
	if(x[0]=='-'){
		x_sign=true;
		string temp;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x=temp;
	}
	if(y[0]=='-'){
		y_sign=true;
		string temp;
		int l = y.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(y[i]);
		}
		y=temp;
	}
	if(x[0]=='+'){
		x_sign=false;
		string temp;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x=temp;
	}
	if(y[0]=='+'){
		y_sign=false;
		string temp;
		int l = y.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(y[i]);
		}
		y=temp;
	}
	if(x_sign^y_sign){
		ans.push_back('-');
	}
	ans.append(BigInt::mulHelper(x,y));
	return *(new BigInt(ans)); 

}


BigInt BigInt::div(long long int y){
	string ans;
	string x = this->var;
	if(x.find("inf")!=string::npos){
		return *this;
	}
	bool x_sign = false;
	bool y_sign = false;
	if(x[0]=='-'){
		x_sign=true;
		string temp;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x=temp;
	}
	if(y<0){
		y_sign = true;
		y = y * -1;
	}
	if(x[0]=='+'){
		x_sign=false;
		string temp;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x=temp;
	}
	if(x_sign^y_sign){
		ans.push_back('-');
	}
	ans.append(BigInt::divHelper(x,y));
	return *(new BigInt(ans)); 
}

BigInt BigInt::mod(long long int y){
	string quotient = BigInt::divHelper(this->var, y);
	string product = BigInt::mulHelper(quotient,to_string(y));
	string ans = BigInt::subHelper(this->var, product);
	if(BigInt::allZeroes(ans)){
		return *(new BigInt("0"));
	}
	return *(new BigInt(ans));
}

BigInt BigInt::fact(int y){
	if(y==0||y==1){
		return *(new BigInt("1")); 
	}
	string ans = "1";
	for(int i=2 ; i<=y ; i++){
		ans = BigInt::mulHelper(ans,to_string(i));
	}
	return *(new BigInt(ans));
}

BigInt BigInt::pow(string x, int y){
	if(y==0){
		return *(new BigInt("1")); 
	}
	if(y==1){
		return *(new BigInt(x));
	}
	bool x_sign = false;
	if(x[0]=='-'){
		string temp;
		x_sign = true;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x = temp;
	}
	if(x[0]=='+'){
		string temp;
		int l = x.length();
		for(int i=1 ; i<l ; i++){
			temp.push_back(x[i]);
		}
		x = temp;
	}
	string temp2 = x;
	for(int i=2 ; i<=y ; i++){
		temp2 = BigInt::mulHelper(x,temp2);
	}
	string ans;
	if(x_sign && (y%2)){
		ans.push_back('-');
	}
	ans.append(temp2);
	return *(new BigInt(ans));
}

BigInt BigInt::abs(){
	string x = this->var;
	if(x[0]=='-'){
		x[0]='+';
	}
	return *(new BigInt(x)); 
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

BigInt BigInt::operator - (BigInt const &obj){
	return this->sub(obj);
}

BigInt BigInt::operator - (){
	string ans;
	string x = this->var;
	if(x[0]=='-'){
		ans=x;
		ans[0]='+';
		return *(new BigInt(ans));
	}
	if(x[0]=='+'){
		ans=x;
		ans[0]='-';
		return *(new BigInt(ans));
	}
	ans.push_back('-');
	ans.append(x);
	return *(new BigInt(ans));
}

BigInt BigInt::operator * (BigInt const &obj){
	return this->mul(obj);
}

BigInt BigInt::operator / (long long int y){
	return this->div(y);
}

BigInt BigInt::operator % (long long int y){
	return this->mod(y);
}

bool BigInt::isSmaller(string x, string y){
	int n1 = x.length(), n2 = y.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++)
    if (x[i] < y[i]) 
        return true; 
    else if (x[i] > y[i]) 
        return false; 
  
    return false; 
}

string BigInt::subHelper(string x , string y){
	if(BigInt::isSmaller(x,y)){
		swap(x,y);
	}
	int l1 = x.length();
	int l2 = y.length();
	reverse(x.begin(), x.end()); 
	reverse(y.begin(), y.end()); 
	int carry = 0;
	string ans;
	
	for (int i=0; i<l2; i++) 
	{ 
		int sub = ((x[i]-'0')-(y[i]-'0')-carry); 	
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 

		ans.push_back(sub + '0'); 
	} 

	for (int i=l2; i<l1; i++) 
	{ 
		int sub = ((x[i]-'0') - carry); 
		
		
		if (sub < 0) 
		{ 
			sub = sub + 10; 
			carry = 1; 
		} 
		else
			carry = 0; 
			
		ans.push_back(sub + '0'); 
	} 

	
	reverse(ans.begin(), ans.end()); 

	return ans; 
}


string BigInt::mulHelper(string x , string y){
	int len1 = x.size(); 
    int len2 = y.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    vector<int> result(len1 + len2, 0); 
   
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = x[i] - '0'; 
  
        
        i_n2 = 0;  
          
                      
        for (int j=len2-1; j>=0; j--) 
        { 
             
            int n2 = y[j] - '0'; 
  
            
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            
            carry = sum/10; 
  
            
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
       
        i_n1++; 
    } 
   
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
   
    if (i == -1) 
    return "0"; 
   
    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
}

string BigInt::divHelper(string x , long long int y){
	
	string ans; 
    if(y==0){
		return "inf";
	}
    int idx = 0; 
    long long int temp = x[idx] - '0'; 
    while (temp < y) 
        temp = temp * 10 + (x[++idx] - '0'); 
  
    while (x.size() > idx) { 
        
        ans += (temp / y) + '0'; 
  
        
        temp = (temp % y) * 10 + x[++idx] - '0'; 
    } 
       
    if (ans.length() == 0) 
        return "0"; 

    return ans; 
}

bool BigInt::allZeroes(string x){
	int l = x.length();
	for(int i = 0 ; i < l ; i++){
		if(x[i]=='1' || x[i]=='2' || x[i]=='3'||x[i]=='4' || x[i]=='5' || x[i]=='6'||x[i]=='7' || x[i]=='8' || x[i]=='9'){
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const BigInt& obj){
	os<<obj.var;
	return os;
}
