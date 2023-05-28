#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;
int book[100];

int bok(int x){
	while(x){
		int a=x%10;
		x=x/10;
		if(book[a]==0) book[a]=1;
		else return 0;
	}
	return 1;
}

int main(){
	
	for(int i=100;i<=400;i++){
		int a=i;
		int b=i*2;
		int c=i*3;
		for(int i=0;i<=9;i++) book[i]=0;
		if((bok(a)+bok(b)+bok(c))==3){
			printf("%d\n%d\n%d\n\n",a,b,c);
		}
	}
	return 0;
}

