//д�����������ˣ������Ƿ���  �����콲����   �ݹ��� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double dfs(){
	string a;
	cin>>a;
	switch(a[0]){
		case '+':return dfs()+dfs();
		case '-':return dfs()-dfs();
		case '*':return dfs()*dfs();
		case '/':return dfs()/dfs();
		default: return atof(a.c_str()); //string.c_str()�Ƿ���string���͵�C����ַ�����ʼ��ַ��������Ҳ�ǵ�ַ�� 
	}
}
int main(){
	freopen("expression.in","r",stdin);
	freopen("expression.out","w",stdout);
	printf("%.6lf",dfs());//���ȿ��� 
	return 0;
}

