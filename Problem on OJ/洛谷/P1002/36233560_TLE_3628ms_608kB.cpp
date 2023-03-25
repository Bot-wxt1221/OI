#include <iostream>
using namespace std;
int dfs(int x,int y);
class pos{
    public:
        int x=0,y=0;
};
pos b,h,no[8];
int main(){
    cin>>b.x>>b.y>>h.x>>h.y;
    no[0].x=h.x-2;no[0].y=h.y-1;
    no[1].x=h.x-1;no[1].y=h.y-2;
    no[2].x=h.x+2;no[2].y=h.y-1;
    no[3].x=h.x+1;no[3].y=h.y-2;
    no[4].x=h.x-2;no[4].y=h.y+1;
    no[5].x=h.x-1;no[5].y=h.y+2;
    no[6].x=h.x+2;no[6].y=h.y+1;
    no[7].x=h.x+1;no[7].y=h.y+2;
    cout<<dfs(0,0);
}
int dfs(int x,int y){
	for(int i=0;i<8;i++){
		if(x==no[i].x&&y==no[i].y){
			return 0;
		}
	}
	if(x==h.x&&y==h.y){
		return 0;
	}

	if(x>b.x||y>b.y){
		return 0;
	}
	if(x==b.x&&y==b.y){
		return 1;
	}
	return dfs(x+1,y)+dfs(x,y+1); 
}