#include <iostream>
#include <cstdio>
using namespace std;
char a[50];
bool vised[128];
char b[7]={' ','D','A','E','C','B'};
char c[7]={' ','A','B','C','D','E'};
char temp[7]={' ','E','D','A','C','B'};
void dfs(int step);
int n; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	dfs(1);
	return 0;
}
void dfs(int step){
	if(step==n+1){
		int t1=0,t2=0;
		for(int i=1;i<=5;i++){
			if(a[i]==(i-1+'A')){
				return ;
			}
		}
		for(int i1=2;i1<=5;i1++)
			for(int j=2;j<=5;j++)
				if(a[i1]==c[j]&&a[i1-1]==c[j-1]){
					return ;
				}
		for(int i1=1;i1<=5;i1++)
			if(a[i1]==b[i1]){
				t1++;
			}
		for(int i1=2;i1<=5;i1++)
			for(int j=2;j<=5;j++)
				if(a[i1]==b[j]&&a[i1-1]==b[j-1]){
					t2++;
				}
		if(t1!=2||t2!=2){
			return ;
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		cout<<endl;
		return ;
	}	
	for(int i='A';i<='E';i++){
		if(vised[i]){
			continue;
		}
		a[step]=i;			
		vised[i]=1;
		dfs(step+1);
		vised[i]=0;
	}
	return ;
}
