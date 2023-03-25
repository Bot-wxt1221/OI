#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
string s[32]{"Brazil", "Croatia", "Mexico", "Cameroon",
"Spain", "Netherlands", "Chile", "Australia",
"Colombia", "Greece", "Cote d'Ivoire", "Japan",
"Uruguay", "Costa Rica", "England", "Italy",
"Switzerland", "Ecuador", "France", "Honduras",
"Argentina", "Bosnia and Herzegovina", "Iran",
"Nigeria", "Germany", "Portugal", "Ghana",
"USA", "Belgium", "Algeria", "Russia",
"Korea Republic"};
int ax=-1,cnt;
//ax -> the maximum of the purpose length
//cnt -> the number of answers
bool vis[32];
void dfs(string x,int st){
	bool fl=true;
	for(int i=0;i<32;++i){ //choose which countries to be connected
		if(!vis[i]&&s[i][0]+32==x[x.length()-1]){//discuss if the country can be connected
			fl=false;//discuss if there are remaining countries which could be connected
			vis[i]=true;
			dfs(s[i],st+1);
			vis[i]=false;
		}
	}
	if(fl) if(st>ax) ax=st,cnt=0;//if there is a better answer,change ax and cnt
	if(st==ax) ++cnt;//if it's the same as the last answer,add cnt
}
int main(){
	//the first country don't need to discuss if it ans be connected
	for(int i=0;i<32;++i){
		vis[i]=true;
		dfs(s[i],1);
		vis[i]=false;
	}
	//print the right answer
	printf("%d %d",ax,cnt);
	return 0;
}
