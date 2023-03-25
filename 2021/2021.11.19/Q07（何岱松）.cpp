#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

bool check(int a, int b, int c){
	if(b == 4 || b == 6 || b == 9 || b == 11)if(c > 30)return false;
	if(b == 2){
		if(a % 4 == 0) if(c > 28)return false;
		else if(c > 29)return false;
	}
	return true;
}//判断这个日期是否合法 

string get(int p){
	string ans="";
	while(p){
		ans = (char) (p % 2 + '0') + ans;
		p /= 2;
	}
	return ans;
}//把原数转变为二进制 

bool ph(string x){
	if(x[21] == '1' && x[22] == '0' && x[23] == '0' && x[24] == '1')return true;
	return false; 
}//判断最后面四位是不是1001 

bool pa(string x){
	string p = "", q = "";
	for(int i = 4; i <= 20; i++) p = p + x[i];//正着 
	for(int i = 20; i >= 4; i--) q = q + x[i];//反着 
	for(int i=0; i <= 16; i++) if(p[i] != q[i])return false;//判断 
	return true;
}//判断是不是回文数 

int main(){
	for(int y = 1964; y <= 2020; y++){
		for(int m = 1; m <= 12; m++){
			for(int d = 1; d <= 31; d++){
				//三重循环日期 
				if(check(y, m, d) == false) continue;//如果这个日期不合法 
				int p = y * 10000 + m * 100 + d;
				string e = get(p);
				if(!ph(e)) continue; //如果二进制的末尾不是1001 
				if(pa(e)){ //如果是一个回文数 
					if(m < 10 && d >= 10) cout << y << " 0" << m << " " << d << " \t" << e << endl;
					else if(m >= 10 && d < 10) cout << y << " " << m << " 0" << d << " \t" << e << endl;
					else if(m >= 10 && d >= 10) cout << y << " " << m << " " << d << " \t" << e << endl;
					else cout << y << " 0" << m << " 0" << d << " \t" << e << endl;
					//上面四行是特判0的，因为我的代码不是直接模拟二进制，导致比较麻烦 
				}
			}
		}
	}
}
