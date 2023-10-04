//1001 1010 0001 1 
//1001 0101 1101 1
//我们观察发现所有日期二进制都可表示为以下形式 
//1001 xxxx xxxx 0/1 xxxx xxxx 1001 
//我们观察发现二进制只需枚举 "xxxx xxxx" 和"0/1"的部分 
#include<iostream>
#include<cstdio>
#define int unsigned long long
using namespace std;
signed main(){
	register int i,j,x,o,s,n,y,r;
	//"xxxx xxxx"取值,只看第一个"xxxx xxxx" 最小为 93（19641010 == 1001 01011101 1 00101011 0010），最大为 161 （20200724 == 1001 10100001 1 11010001 0100）
	for(i=93;i<=161;++i){//枚举 "xxxx xxxx"
		x=i;j=0;
		while(x>0){
			j|=x&1;
			j<<=1;
			x>>=1;
			
		}x=i;j>>=1;
		for(o=0;o<2;++o){//枚举 "0/1"
			// 拼接各部分 
			//  1001      xxxx      0/1      xxxx    1001
			s=(9<<21) | (x<<13) | (o<<12) | (j<<4) | 9;
			if(s<19641010||s>20200724) continue;
			n=s/10000;		//年 
			y=(s%10000)/100;//月 
			r=s%100;		//日 
			if(y<1||y>12) continue;
			if(y<8){//8月以前 大月为 奇数 
				if(y&1&&r<32&&r>0) printf("%u\n",s);
				else if(y==2){ 
					//对于二月在闰年的特殊处理 
					//因为1966~2020 中能被 100 整除的只有 2000,且它刚好 能被 400 整除
					//所以只需判断能否被 4 整除 
					if(n%4==0&&r>0&&r<30) printf("%u\n",s);
					else if(r>0&&r<29) printf("%u\n",s);
				}
				else if(!(y&1)&&r<31&&r>0) printf("%u\n",s);
			}//8月以后 大月为 偶数 
			else if(y&1&&r<31&&r>0) printf("%u\n",s);
			else if(!(y&1)&&r<32&&r>0) printf("%u\n",s);
		}
	}
	return 0;
}
