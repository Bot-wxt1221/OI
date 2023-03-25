	#include <iostream>
	#include <cstdio>
	#define Maxs 105
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
	bool have[1005];
	int queue[Maxs];
	int size=0;
	int r=0,l=0;
	int main(){
		freopen("machine.in","r",stdin);
		freopen("machine.out","w",stdout);
		int m,n;
		m=read();
		n=read();
		int find=0;
		for(int i=1;i<=n;i++){
			int temp=read();
			if(have[temp]){//有缓存 
				continue;
			}else if(size==m){//没缓存而且内存已满 
				have[queue[r]]=0;
				r++;
				r=r%Maxs;
				queue[l]=temp;
				l=(l+1)%Maxs; 
				have[temp]=1;
			}else{//没缓存但内存没满 
				size++;
				queue[l]=temp;
				l=(l+1)%Maxs; 
				have[temp]=1;
			}
			find++;
		}
		cout<<find;
		return 0;
	}
	/*
	Anything about this program:
	Type:
		评测 
	Description:
		这个翻译软件的原理很简�