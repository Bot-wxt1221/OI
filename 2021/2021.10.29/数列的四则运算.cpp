#include <iostream>
#include <algorithm>
using namespace std;
char op[2]={' ','*'};
int main(){
	for(int i=1E3;i<1E4;i++){
		int a = i / 1000, b = i % 1000 / 100, c = i % 100 / 10, d = i % 10;
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				for(int l=0;l<2;l++){
					int t1=a,t2=b,t3=c,t4=d;
					if(j==0){
						t2+=t1*10;
						t1=1;
					}
					if(k==0){
						t3+=t2*10;
						t2=1;
					}
					if(l==0){
						t4+=t3*10;
						t3=1;
					}
					int all=t1*t2*t3*t4;
					if((l|j|k)&&all==d * 1000 + c * 100 + b * 10 + a){
						cout<<i<<' ';
					}
				}
			}
		}
	}
}
