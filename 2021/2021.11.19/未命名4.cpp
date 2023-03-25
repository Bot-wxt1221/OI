#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector <stack <int> > len;
stack <int> dis;
int _max=0;
void dfs(int x,int l);
bool use[65];
string a[65]={"","Brazil", "Croatia", "Mexico", "Cameroon",
"Spain", "Netherlands", "Chile", "Australia",
"Colombia", "Greece", "Cote d'Ivoire", "Japan",
"Uruguay", "Costa Rica", "England", "Italy",
"Switzerland", "Ecuador", "France", "Honduras",
"Argentina", "Bosnia and Herzegovina", "Iran",
"Nigeria", "Germany", "Portugal", "Ghana",
"USA", "Belgium", "Algeria", "Russia",
"Korea Republic"};

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	for(int i=1;i<=32;i++){
		dis.push(i);
		dfs(i,1);
		dis.pop();
	}
	for(int i=0;i<len.size();i++){
		while(!len[i].empty()){
			cout<<a[len[i].top()]<<' ';
			len[i].pop();
		}
		cout<<endl;
	}
	cout<<_max;
	return 0;
}
void dfs(int x,int l){
	bool flag=0;
	for(int i=1;i<=32;i++){
		if(use[i])	continue;
		if(a[x][a[x].size()-1]==a[i][0]+32){
			cout<<a[x][a[x].size()-1]<<' '<<a[i][0]-'a'+'A';
			flag=1;
			dis.push(i);
			use[i]=1;
			dfs(i,l+1);
			use[i]=0;
			dis.pop();
		}
	}
	if(flag==0){
		if(_max<l){
			_max=l;
			len.clear();
			len.push_back(dis);
		}else if(_max==l){
			len.push_back(dis);
		}
	}
}
