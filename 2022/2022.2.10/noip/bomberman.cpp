#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
class pos{
	public:
		int x,y;
};
char asa[105][105];
vector<pos>a;
vector<pos>anss;
bool cmp(pos a,pos b){
	return a.x=b.x?a.x<b.x:a.y<b.y; 
}
int main(){
	freopen("bomberman.in","r",stdin);
	freopen("bomberman.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>asa[i][j];
			if(asa[i][j]=='.'){
				pos temp;
				temp.x=i,temp.y=j;
				a.push_back(temp);
			}
		}
	}
	if(a.size()==0){
		cout<<-1;
		return 0;
	}
	int _max=0;
	for(int i=0;i<a.size();i++){
		int ans=0;
		int ax=a[i].x,ay=a[i].y;
		while(1){
			ax--;
			if(asa[ax][ay]=='#'){
				break;
			}
			if(asa[ax][ay]=='G'){
				ans++; 
			}
			if(ax>n&&ay>m){
				break;
			}
		}
		ax=a[i].x,ay=a[i].y;
		while(1){
			ax++;
			if(asa[ax][ay]=='#'){
				break;
			}
			if(asa[ax][ay]=='G'){
				ans++; 
			}
			if(ax>n&&ay>m){
				break;
			}
		}
		ax=a[i].x,ay=a[i].y;
		while(1){
			ay--;
			if(asa[ax][ay]=='#'){
				break;
			}
			if(asa[ax][ay]=='G'){
				ans++; 
			}
			if(ax>n&&ay>m){
				break;
			}
		}
		ax=a[i].x,ay=a[i].y;
		while(1){
			ay++;
			if(asa[ax][ay]=='#'){
				break;
			}
			if(asa[ax][ay]=='G'){
				ans++; 
			}
			if(ax>n&&ay>m){
				break;
			}
		}
		if(ans==_max){
			anss.push_back(a[i]);
		}else if(ans>_max){
			anss.clear();
			anss.push_back(a[i]);
			_max=ans;
		}
	}
	sort(anss.begin(),anss.end(),cmp);
	if(_max==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<anss.size();i++){
		printf("%d %d\n",anss[i].x,anss[i].y);
	}
	printf("%d",_max);
	return 0;
}

