#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string temp;
vector<string>a;
int dfs(vector<string>&a,int now);
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	int n=0;
	while(cin>>temp){
		a.push_back(temp);
	}
	n--;
	sort(a.begin(),a.end());
	printf("%d",dfs(a,-1));
	return 0;
}
int dfs(vector<string>&a,int now){
	if(a.size()==0){
		return 0;
	}
	if(a.size()==1){
		return a[0].size()-now;
	}
	vector<string>b;
	int ans=0;
	for(int i='A';i<='Z';i++){
		b.clear();
		for(int j=0;j<a.size();j++){
//			cout<<a[j]<<endl;
			if(a[j].size()>=now+2&&a[j][now+1]==i){
				
				b.push_back(a[j]);
			}
		}
		
		ans+=dfs(b,now+1);
	}
	return ans+1;
}


