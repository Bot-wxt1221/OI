#include <iostream>
#include <algorithm>
using namespace std;
bool huiwen(string a){
	string b=a;
	reverse(a.begin(),a.end());
	if(a==b){
		return true;
	}
	return false;
}
string to(int i,int b){
	string a="";
	while(i){
		a=a+char(i%b);
		i=i/b;
	}
	reverse(a.begin(),a.end());
	return a;
}
bool yes(int a){
	if(huiwen(to(a,2))&&huiwen(to(a,8))&&huiwen(to(a,10))){
		return 1;
	}
	return 0;
}
int main(){
	for(int i=11;1;i++){
		if(yes(i)){
			cout<<i;
			return 0;
		}
	}
}
