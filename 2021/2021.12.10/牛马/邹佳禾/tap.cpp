#include<iostream>
#include<cstdio>
using namespace std;
void dfs(int last,int value,int x);//last：上一个是几个 ，value:已经有几个插孔了，x：如果全部都插入的话就会产生很多层 
int n,ans=0;
int main(){
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	
	cin>>n;
	dfs(2,2,1);
	dfs(3,3,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


void dfs(int last,int value,int x){
	//if(value>n) return;
	if(value==n){
		ans++;
		return;
	}
	if(value<n){
		for(int i=1;i<=x;i++)
			for(int j=1;j<=last;j++){
				dfs(2+j*j-i*i,value+j,i);
				dfs(j,value+j+j,j);
			}
		
		
	}
	
	
}
