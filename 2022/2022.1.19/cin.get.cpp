#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char ch[20];
	cin.get(ch,10,'o');//Լ��   ��ֹ��Ϊ'o' 
	cout<<ch<<endl; 
	return 0;
}
//������ֱֹ��ֹͣ 
