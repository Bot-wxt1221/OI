//���ƣ�����û�����ݷ�Χ�����Թ�����¼���� 

/*������(n-1)�����ӵķ�������������һ��1*1���ɵô�
������(n-2)�����ӵķ�������������һ��1*2���ɵô�
������(n-3)�����ӵķ�������������һ��1*3���ɵô�
*/
#include <iostream>
#include <cstdio>
using namespace std;
long long read(){//�������Ҳ��֪����ΪʲôҪ�� 
	long long x=0,f=1;char c=getchar();
	while('0'>c||'9'<c)	c=='-'?f=-1:1,c=getchar();
	while('0'<=c&&c<='9')	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
int main(){
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	long long n=read(); 
	long long n1,n2,n3;//���� n1ǰ1�� n2ǰ2�� n3ǰ3��   
	n1=4,n2=2,n3=1;//��ʼ�� 
	if(n==0){//���У���Ȼ��� 
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<2;
		return 0;
	}
	if(n==3){
		cout<<4;
		return 0;
	}
	long long temp;
	for(long long i=4;i<=n;i++){//���� 
		temp=n1+n2+n3;
		n3=n2,n2=n1,n1=temp;
	}
	cout<<temp;
	return 0;
}

