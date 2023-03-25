#include <iostream>
using namespace std;
long long ans[25][25];
bool s[25][25];
const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
class pos {
	public:
		int x=0,y=0;
};
pos b,h,no[8];
int main() {
	cin>>b.x>>b.y>>h.x>>h.y;
	b.x+=2;
	b.y+=2;
	h.x+=2;
	h.y+=2;
	s[h.x][h.y]=1;
    for(int i = 1; i <= 8; i++)
        s[ h.x + fx[i] ][ h.y + fy[i] ] = 1;
	ans[2][2]=1;
    for(int i = 2; i <= b.x; i++){
        for(int j = 2; j <= b.y; j++){
            if(s[i][j])continue;
            ans[i][j] = max( ans[i][j] , ans[i - 1][j] + ans[i][j - 1] ); 
        }
    }
	cout<<ans[b.x][b.y];
}