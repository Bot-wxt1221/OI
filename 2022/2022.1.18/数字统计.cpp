#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int n[21][13]; 
int main(){
	srand(time(NULL));
	for(int i=1;i<=1000;i++){
		int a,b;
		a=rand()%20+1,b=rand()%12+1;
		n[a][b]++;
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j<=12;j++){
			printf("%d院%d系有%d个老师\n",i,j,n[i][j]);
		}
	}
	return 0;
}
