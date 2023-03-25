#include <iostream> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring>
using namespace std;
bool vis[1005];
char e[105]; 
char t[105];
void check(int y,int m,int d){//检测是否为合法日期
	if(y<=1963||y>=2021||m<0||m>12||d>32||d<0) return ;
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) if(d>31) return ;
	if(m==9||m==4||m==6||m==11) if(d>30) return ;
	if(y%4!=0) if(d>28) return ;
	if(y%100==0) if(y%400!=0) if(d>28) return ;
	cout<<y<<" "<<m<<" "<<d<<endl;
	return ;
}
inline void dfs(int step){//1~17位为年份，18~21位为月份，22~25位为日。 
	if(step>18) return;
	if(step==18) {//判断边界 
		t[1]='1',t[2]='0',t[3]='0',t[4]='1';
		t[25]='1',t[24]='0',t[23]='0',t[22]='1';// 前四位和后四位提前确定 
		int y=0,m=0,d=0,num=0;
		for(int i=25,o=1;i>=1;i--,o*=2){
			num+=(t[i]-'0')*o;
		}//题意说倒着和正着算出来要一样，num求倒着算，num1正着算 
		int num1=0;
		for(int i=1,o=1;i<=25;i++,o*=2){
			num1+=(t[i]-'0')*o;
		}
		d=num%100;
		y=num/10000;
		m=(num-y*10000)/100;//取年月日 
		if(num1==num)//两者相等，判断是否为合法日期 
		check(y,m,d);
		return;
	}
	for(int k=1;k<=2;k++){//深搜找出所有的日期 
		if(vis[step]==0){
			vis[step]=1;
			t[step+4]=k-1+'0';//用二进制存，0或1 
//			cout<<step;
			dfs(step+1);
			vis[step]=0;
		}
	}
	return;
}
int main(){
	dfs(1);
} 
