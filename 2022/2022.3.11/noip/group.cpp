
/*
�����һͷһβ���ǣ�ʹ���±��������ɨ�� 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
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
int a[30005];
int main(){
	freopen("group.in","r",stdin);
	freopen("group.out","w",stdout);
	int w,n,ans=0,more=w;
	w=read();
	n=read();
	more=w;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);//���� 
	while(l<r){
		if(a[l]+a[r]<=w){//��һ��װ 
			ans++;
			l++,r--;
		}else{//����һ��װ 
			ans++;
			r--;
		}
	}
	if(l==r){
		ans++;//��ʣһ�� 
	}
	cout<<ans;
	return 0;
}

