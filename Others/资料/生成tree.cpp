#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
int fa[1000005];
int getroot(int n){
	return fa[n]==n?n:fa[n]=getroot(fa[n]);
}
vector <int> used;
int main(){
	freopen("farm6.in","w",stdout);
	int n;
	cin>>n;
	cout<<n<<endl;
	int root=1;
	used.push_back(root);
	int have=1;
	srand(time(NULL));
	bool a=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	while(have<n){
		a=0;
		while(!a){
			int now=rand()%used.size(),now2=rand()%n+1;
			now=used[now];
			if(now==now2||getroot(now)==getroot(now2)){
				continue;
			}
			fa[getroot(now)]=fa[getroot(now2)];
			cout<<now<<' '<<now2<<endl;
			used.push_back(now2);
			a=1;
		}
		have++;
	}
}
