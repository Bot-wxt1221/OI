#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
string a;
int cnt=0;
int yue[13]={31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int x,string d);   //x作为日期是否合法   闰年判定   是否会文 
void dfs(int step);   //枚举   连接 
int to_shi(string x); 
int c(int x);  //求2的x次方 
/*
19641010  1001010111011001010110010
20200724  1001101000011110100010100
*/
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dfs(0);
	cout<<cnt;
	return 0;
}
void dfs(int step){
	if(step==21){
		string tem=a;
		tem="1001"+tem;
		int temp=to_shi(tem);
		if(19641010>=temp||temp>=20200713){
			return;
		}
		
		if(!check(temp,tem)){
			return;
		}
		cnt++;
		printf("%d\n",temp);
		return;
	}
	for(int i=0;i<=1;i++){
		string temp=a;
		a=a+char(i+'0');
		dfs(step+1);
		a=temp;
	}
	return ;
}
int to_shi(string x){
	int temp=0;
	for(int i=0;i<x.length();i++){
		temp+=(x[i]-'0')*c(x.length()-i-1);
	}
	return temp;
}



int c(int x){
	if(x==0){
		return 1;
	}
	if(x%2==0){
		int temp=c(x/2);
		return temp*temp;
	}
	return c(x-1)*2;
}



bool check(int x,string d){
	int a=x/10000;
	int b=(x%10000)/100;
	int c=(x%100);
	if(1964>a||a>2020||b<1||b>12){
		return false;
	}
	if(((a%100==0)?(a%400==0):(a%4==0))){
		if((c<1||c>29)&&b==2) {
			return false;
		}
		else{
			if((c<1||c>yue[b])){
				return false;
			}
		}
	}else{
			if((c<1||c>yue[b])){
				return false;
			}
		}
	reverse(d.begin(),d.end());
	if(x==to_shi(d)){
		return true;
	}
	return false;
}
