#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<string>a;
int main(){
//	freopen("save.in","r",stdin);
//	freopen("save.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		string temp,t2;
		cin>>temp>>t2;
		int nans=0;
		for(int j=0;j<t2.size()-2;j++){
			if(t2[j]=='s'&&t2[j+1]=='o'&&t2[j+2]=='s'){
				nans++;
			}
		} 
		if(nans==ans){
			a.push_back(temp);
		}else if(nans>ans){
			a.clear();
			a.push_back(temp);
			ans=nans;
		}
	}
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<' ';
	}
	cout<<endl<<ans;
	return 0;
}
