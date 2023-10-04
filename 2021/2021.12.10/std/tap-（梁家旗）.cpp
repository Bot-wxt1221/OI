#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long f[10005];
long long int ap[100009]={0,1,4,10,20,35,56};
long long int t[100009]={0,6,10,15,21,28};
void init(){//初始化数组 
//t数组为辅助计算的数组，为ap数组每两个数的差
//ap数组为最后3个插头相等电器的方案数 
	for(int i=6;i<=100005;i++){
		t[i]+=t[i-1]+i+2; //
	}
	for(int i=4;i<=100005;i++){
		ap[i]=ap[i-1]+t[i-2];
	} 
}
int main(){
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	init();
	f[0]=0;
	f[1]=0;//0和1是插头不够，没有方案 
	f[2]=1;
	f[3]=2;
	f[4]=4;
	f[5]=f[4]+f[3]*f[2]+f[3]+f[2]*f[2];//f数组初始化 
	int n;cin>>n;
	f[6]=f[5]+f[4]+3+f[4]*f[2]+f[2]*f[2]*f[2]+f[2]*f[3];
	for(int j=7;j<=n;j++){//j个电器插线的方案总数计算
	//分情况讨论，分两个插头和三个插头
	//当两个插头时，只接一个时，此时方案总数为f[i-1]
	//当三个插头时，只接一个时，此时方案总数为f[i-2] 
		f[j]+=f[j-1]+f[j-2]; 
		for(int i=1;i<=j/2;i++){//当有两个插头时，都接上，此时方案数为 f[a]*f[b](a+b==j且a！=b) 
			if(i==j-i){//i与j-i相等时，方案总数应为1+2+3+...+f[i]，用等差数列求和 
				f[j]+=(f[i]*(f[i]+1))/2;
			}
			else f[j]+=(f[i]*f[j-i]);
		}
		//当有三个插头时，接两个 
		for(int i=1;i<=(j-1)/2;i++) {		//同理，此时a+b和为j-1 
			if(i==j-i-1){
				f[j]+=(f[i]*(f[i]+1))/2;
			}
			else f[j]+=f[i]*f[j-1-i];
		}
		//当有三个插头时，三个都接上 
		for(int a=2;a<=j;a++){
			for(int b=a;b<=j;b++){
				for(int c=b;c<=j;c++){//枚举每个插头接的电器的数量，保证不重复 
					if(a+b+c==j){ 
						if(a==b&&b==c) f[j]+=ap[f[a]];//当三个插头数量相等时 
						else if(a==b){
							f[j]+=((f[a]*(f[a]+1))/2)*f[c];//当两个插头数量相等时，应是这两个插头的方案数乘上另外一个插头的方案数 
						}
						else if(c==b){
							f[j]+=((f[c]*(f[c]+1))/2)*f[a];//同理 
						}
						else if(a==c){
							f[j]+=((f[a]*(f[a]+1))/2)*f[b];//同理 
						}
						else
							f[j]+=f[a]*f[b]*f[c];//若三个都不相等，则应为这三个插头方案数相乘 
						
					}
				}
			}
		} 
	}
	cout<<f[n];//输出最终结果 
}

