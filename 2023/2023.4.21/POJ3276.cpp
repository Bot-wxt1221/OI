#include <iostream>
#include <cstdio>
inline int read();
int cha[5005];
int a[5005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        char temp[10];
        scanf("%s",temp);
        a[i]=(temp[0]=='F'?0:1);//all 0
    }
    int mink=0,minm=0x3f3f3f3f;
    for(int k=1;k<=n;k++){
        int anas=0;
        for(int i=1;i<=n;i++){
            cha[i]=0;
        }
        int temp=0;
        for(int i=1;i<=n-k+1;i++){
            temp+=cha[i];
            if(a[i]==0&&temp%2==0){
            }else if(a[i]==1&&temp%2==1){
            }else{
                anas++;
                cha[i]++;
                temp++;
                cha[i+k]--;
            }
        }
        bool ans=1;
        for(int i=n-k+2;i<=n;i++){
            temp+=cha[i];
            if(a[i]==0&&temp%2==0){
            }else if(a[i]==1&&temp%2==1){
            }else{
                ans=0;
            }
        }
        if(ans){
            if(anas<minm){
                minm=anas;
                mink=k;
            }
        }
    }
    printf("%d %d",mink,minm);
	return 0;
}
inline int read(){
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
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


