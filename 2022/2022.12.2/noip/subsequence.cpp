#include <iostream>
#include <cstdio>
inline int read();
int a[100005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("subsequence.in","r",stdin);
	freopen("subsequence.out","w",stdout);
	#endif
    int n,s;
    while(scanf("%d%d",&n,&s)!=EOF){
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        int ans=0x3f3f3f3f;
        int l=1,r=0;
        int sum=0;
        while(r<=n&&l<=n){
            if(sum<s){
                r++;
                sum+=a[r];
            }else{
                ans=std::min(ans,r-l+1);
                l++;
                sum-=a[l-1];
            }
        }
        if(ans==0x3f3f3f3f){
            printf("0\n");
        }else
            printf("%d\n",ans);
    }
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
文件名：subsequence.cpp
输入文件：subsequence.in
输出文件：subsequence.out
时限：1秒
空间：256M

题目大意：
        有 n 个正整数组成一个序列。给定整数 S，求长度最短的连续序列，使它们的和大于或等于 S。

输入：
        输入包含多组数据。每组数据的第一行为整数 n 和 S（10＜n≤100000，S＜10^8）；第二行为 n 个正整数，均不超过 10000。输入结束标志为文件结束符（EOF）。

输出：
        对于每组数据，输出满足条件的最短序列的长度。如果不存在，输出 0。

*/


