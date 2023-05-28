#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
inline int read();
bool vised[105][105];
int map[105][105];
int dis[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int t[105][105];
class node{
    public:
        int x,y,dis;
        node(int xx=0,int yy=0,int dd=0){
            x=xx;
            y=yy;
            dis=dd;
        }
};
std::queue<node>a;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	#endif
    int w,h;
    scanf("%d%d",&w,&h);
    getchar();
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char temp=getchar();
            t[j][i]=(temp=='X')?1:0;
        }
        getchar();
    }
    int x1,y1,x2,y2;
    x1=read();
    y1=read();
    x2=read();
    y2=read();
    while((x1!=0||y1!=0||x2!=0||y2!=0)){
        memset(map,0x3f,sizeof(map));
        memset(vised,0,sizeof(vised));
        a=std::queue<node>();
        a.push(node(x1,y1,0));
        map[x1][y1]=0;
        while(a.size()>0){
            node temp=a.front();
            a.pop();
            if(temp.x==0&&temp.y==0){
                // std::cout<<std::endl;
            }
            for(int to=0;to<4;to++){
                int yes=1;
                int ii=1;
                while(yes){
                    int nx=temp.x+dis[to][0]*ii;
                    int ny=temp.y+dis[to][1]*ii;
                    ii++;
                    if(map[1][0]==2){
                        // std::cout<<std::endl;
                    }
                    if(nx<0||ny<0||nx>w+2||ny>h+2){
                        yes=0;
                        break;
                    }
                    if(map[nx][ny]!=0x3f3f3f3f&&map[nx][ny]<temp.dis+1){
                        yes=0;
                        break;
                    }
                    
                    if(t[nx][ny]==0){
                        vised[nx][ny]=1;
                        map[nx][ny]=std::min(map[nx][ny],temp.dis+1);
                        a.push(node(nx,ny,map[nx][ny]));
                    }else if((!vised[nx][ny])){
                        yes=0;
                        vised[nx][ny]=1;
                        map[nx][ny]=std::min(map[nx][ny],temp.dis+1);
                        break;
                    }else{
                        yes=0;
                        break;
                    }
                }
            }
        }
        printf("%d\n",map[x2][y2]==0x3f3f3f3f?0:map[x2][y2]);
        x1=read();
        y1=read();
        x2=read();
        y2=read();
    }
    return 0;
}
	
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


