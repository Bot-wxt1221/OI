#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int k,n;
bool b[60];
int a[60];
void dfs(int ,int );
int total=0;
int main(){
//	freopen("ruler.in","r",stdin);
//	freopen("ruler.out","w",stdout);
	cin>>n>>k;
	dfs(1,0);
	cout<<total/2;
	return 0;
}
void dfs(int step,int last){
	if(step==k+1){
		for(int i = 1; i <= n; i++)  b[i] = 0;
			for(int i = 1; i <= 7; i++) {
				b[n] = 1; b[a[i]] = 1; b[n - a[i]] = 1;				          	
				for(int j = i + 1; j <= 7; j++)
					b[abs(a[j] - a[i])] = 1;
				}
				int t = 0;
				for(int i = 1; i <= n; i++)  t += b[i];
			 	if(t == n){
					int flag = 0;
					for(int i = 1; i <= 4; i++){
					if(a[i] != n - a[8-i]){
					   	flag = 1;
					    break;
					}
				}									
				if(flag) total++; else total += 2;							
			}
		return ;
	}
	for(int i=last+1;i<=n;i++){
		a[step]=i;
		dfs(step+1,i);
	}
	return ;
}
