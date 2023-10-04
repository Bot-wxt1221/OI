#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
vector<int>m[30];
char a1[30],b1[30];
string a2,b2;
int n;
void find(int h,int  &x,int &y){
	for(int i=0;i<n;i++){
		for(int j=0;j<m[i].size();j++){
			if(m[i][j]==h){
				x=i;
				y=j;
				return ;
			}
		}
	}
	return ;
}
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	n=read();
	for(int i=0;i<n;i++){
		m[i].push_back(i);
	}
	scanf("%s",a1);
	a2=a1;
	int a,b;
	if(a2!="quit"){
        a=read();
        scanf("%s",b1);
        b2=b1;
        b=read();
	}
	while(a2!="quit"){
		int x,y;
		int x1,y1;
		find(a,x,y);
		find(b,x1,y1);
		if(x==x1){
			scanf("%s",a1);
			a2=a1;
			if(a2=="quit"){
    	        break;
			}
			a=read();
			scanf("%s",b1);
			b2=b1;
			b=read();
			continue;
		}
		if(a2=="move"){
			if(b2=="onto"){
				int x,y;
				find(a,x,y);
				for(int i=y+1;i<m[x].size();i++){
					m[m[x][i]].push_back(m[x][i]);
				}
				m[x].resize(y);
				find(b,x,y);
				for(int i=y+1;i<m[x].size();i++){
					m[m[x][i]].push_back(m[x][i]);
				}
				m[x].resize(y+1);
				m[x].push_back(a);
			}else{
				int x,y;
				find(a,x,y);
				for(int i=y+1;i<m[x].size();i++){
					m[m[x][i]].push_back(m[x][i]);
				}
				m[x].resize(y);
				find(b,x,y);
				m[x].push_back(a);
			}
		}else{
			if(b2=="onto"){
                int x,y;
                find(b,x,y);
				for(int i=y+1;i<m[x].size();i++){
					m[m[x][i]].push_back(m[x][i]);
				}
				m[x].resize(y+1);
				int x1=x;
				find(a,x,y);
				for(int i=y;i<m[x].size();i++){
					m[x1].push_back(m[x][i]);
				}
				m[x].resize(y);
			}else{
                int x,y;
                find(b,x,y);
                int x1=x;
                find(a,x,y);
                for(int i=y;i<m[x].size();i++){
					m[x1].push_back(m[x][i]);
				}
				m[x].resize(y);
			}
		}
		scanf("%s",a1);
		a2=a1;
		if(a2=="quit"){
            break;
		}
		a=read();
		scanf("%s",b1);
		b2=b1;
		b=read();
	}
	for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<m[i].size();j++){
        	printf(" %d",m[i][j]);
        }
        printf("\n");
	}
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


