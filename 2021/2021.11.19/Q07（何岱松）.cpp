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
}//�ж���������Ƿ�Ϸ� 

string get(int p){
	string ans="";
	while(p){
		ans = (char) (p % 2 + '0') + ans;
		p /= 2;
	}
	return ans;
}//��ԭ��ת��Ϊ������ 

bool ph(string x){
	if(x[21] == '1' && x[22] == '0' && x[23] == '0' && x[24] == '1')return true;
	return false; 
}//�ж��������λ�ǲ���1001 

bool pa(string x){
	string p = "", q = "";
	for(int i = 4; i <= 20; i++) p = p + x[i];//���� 
	for(int i = 20; i >= 4; i--) q = q + x[i];//���� 
	for(int i=0; i <= 16; i++) if(p[i] != q[i])return false;//�ж� 
	return true;
}//�ж��ǲ��ǻ����� 

int main(){
	for(int y = 1964; y <= 2020; y++){
		for(int m = 1; m <= 12; m++){
			for(int d = 1; d <= 31; d++){
				//����ѭ������ 
				if(check(y, m, d) == false) continue;//���������ڲ��Ϸ� 
				int p = y * 10000 + m * 100 + d;
				string e = get(p);
				if(!ph(e)) continue; //��������Ƶ�ĩβ����1001 
				if(pa(e)){ //�����һ�������� 
					if(m < 10 && d >= 10) cout << y << " 0" << m << " " << d << " \t" << e << endl;
					else if(m >= 10 && d < 10) cout << y << " " << m << " 0" << d << " \t" << e << endl;
					else if(m >= 10 && d >= 10) cout << y << " " << m << " " << d << " \t" << e << endl;
					else cout << y << " 0" << m << " 0" << d << " \t" << e << endl;
					//��������������0�ģ���Ϊ�ҵĴ��벻��ֱ��ģ������ƣ����±Ƚ��鷳 
				}
			}
		}
	}
}
