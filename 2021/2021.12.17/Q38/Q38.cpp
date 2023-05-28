#include <iostream>
#include <cstdio>
using namespace std;
bool vised[65570];//short 能表示的最大数是65536   1 黑 0 白 
short newv[65570];
int steps=0;
int head=0,tail=0;
int vise=1;
void bfs();
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	newv[tail++]=0;
	bfs();
	cout<<steps;
	return 0;
}
void bfs(){
	while(head!=tail){
		for(int i=1;i<=4;i++){
			for(int j=1;j<=4;j++){
				short a=newv[head];
				for(int b=1;b<=4;b++)
					a=a^(1<<(16-4*b-j));
				for(int b=1;b<=4;b++)
					a=a^(1<<(16-4*i-b));
				a=a^(1<<(16-4*i-j));
				if(vised[a]==0){
					vised[a]=1;
					newv[tail++]=a;
				}
			}
		}
		steps++;
		head++;
	}
}
