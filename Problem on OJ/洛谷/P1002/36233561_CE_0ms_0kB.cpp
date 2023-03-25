#include <iostream>
using namespace std;
long long ans[25][25];
class pos {
	public:
		int x=0,y=0;
};
pos b,h,no[8];
int main() {
	cin>>b.x>>b.y>>h.x>>h.y;
	no[0].x=h.x-2;
	no[0].y=h.y-1;
	no[1].x=h.x-1;
	no[1].y=h.y-2;
	no[2].x=h.x+2;
	no[2].y=h.y-1;
	no[3].x=h.x+1;
	no[3].y=h.y-2;
	no[4].x=h.x-2;
	no[4].y=h.y+1;
	no[5].x=h.x-1;
	no[5].y=h.y+2;
	no[6].x=h.x+2;
	no[6].y=h.y+1;
	no[7].x=h.x+1;
	no[7].y=h.y+2;
	ans[0][0]=1;
	for(int i=0; i<b.x; i++) {
		for(int j=0; j<b.y; j++) {
			if(i==no[i].x&&j==no[i].y) {
				ans[i][j]=0;
			}
		}
		else if(i==b.x&&j==b.y) {
			ans[i][j]=0;
		} else {
			ans[i][j]=ans[i+1][j]+ans[i][j+1];
		}
	}
}
cout<<ans[b.x][b.y];
}