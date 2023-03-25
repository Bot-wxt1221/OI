#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAXN 100
using namespace std;
vector< vector<int> > a;
vector<int> tesmp;
int book[MAXN+5];
unsigned long long dfs(int step);

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	int _max=0,_m_n[10],temp,temp2[10];
	cin>>n;
	for(int i=1;i<=n;i++){
		temp2[i]=i;
	}
	do{
		for(int i=1;i<=n;i++){
			book[i]=temp2[i];
		}
		temp=dfs(0)-1;
		if(temp>_max){
			_max=temp;
			a.clear();
			tesmp.clear();
			for(int i=1;i<=n;i++){
				tesmp.push_back(temp2[i]);
			}
			a.push_back(tesmp);
		}else if(temp==_max){
			tesmp.clear();
			for(int i=1;i<=n;i++){
				tesmp.push_back(temp2[i]);
			}
			a.push_back(tesmp);
		}
	}while(next_permutation(temp2+1,temp2+n+1));
	cout<<_max<<endl;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
unsigned long long dfs(int step){
	if(book[1]==1){
		return 1;
	}
	int n=book[1];
	reverse(book+1,book+n+1);
	return dfs(step+1)+1;
}
