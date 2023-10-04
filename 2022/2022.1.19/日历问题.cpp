#include <iostream>
#include <cstdio>
using namespace std;
char day[10][10]={"Saturday","Sunday","Monday","Tuesday","Wednesay","Thursday","Friday"};
int c[13]={31,28,31,30,31,30,31,31,30,31,30,31};
int d[13]={31,29,31,30,31,30,31,31,30,31,30,31};
bool run(int a);//ÊÇ·ñÈòÄê 
int more;
int get_dayofweek(int a);
int get_year(int a);
int get_month(int a,int year);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	int a=get_year(n);
	int b=get_month(more,get_year(n));
	int c=more;
	cout<<a<<"-"<<b<<'-'<<c<<' '<<day[get_dayofweek(n)];
	return 0;
}
bool run(int a){
	if(a%100==0?a%400==0:a%4==0){
		return 1;
	}
	
	return 0;
}
int get_dayofweek(int a){
	return (a%7);
}
int get_year(int a){
	int year=2000;
	while(a>0){
		int day=run(year)?366:365;
		if(day<=a){
			a-=day;
			year++;
		}else{
			more=a;
			return year;
		}
	}
}
int get_month(int a,int year){
	int month=1;
	if(run(year)){
		while(a>0){
			if(d[month]<=a){
				a-=d[month];
				month++;
			}else{
				more=a;
				return month;
			}
		}
	}else{
		while(a>0){
			if(c[month]<=a){
				a-=c[month];
				month++;
			}else{
				more=a;
				return month;
			}
		}
	}
}
