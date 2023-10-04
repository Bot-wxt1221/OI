#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 1000
using namespace std;
bool us[MAXN];
bool cn=0;
int n=1;
int habe[MAXN];
void dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(cn==0){
		dfs(0);
		n++;
	}
	cout<<n-1;
	return 0;
}
void dfs(int step){
	if(step==n){
			double a=habe[1]+habe[step];
			a=sqrt(a);
			if(a!=floor(a)){
				return;
			}
		cn=1;
		for(int i=1;i<=step;i++){
			cout<<habe[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(us[i]==1){
			continue;
		}
		if(sqrt(i+habe[step])!=floor(sqrt(i+habe[step]))){
			continue;
		}
		us[i]=1;
		habe[step+1]=i;
		dfs(step+1);
		us[i]=0;
	}
	return;
}
