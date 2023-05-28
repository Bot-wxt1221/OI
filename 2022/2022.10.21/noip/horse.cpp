
#include <iostream>
#include <cstdio>
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
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
class node {
public:
	int x, y, have;
	node( int nx, int ny, int hve )
	{
		x	= nx;
		y	= ny;
		have	= hve;
	}
};
bool operator== ( const node a, const node b ) {
		return(a.x == b.x && a.y == b.y && a.have == b.have);
	}
class hash_cmp {
public:
	bool operator() ( const node a, const node b ) const
	{
		return(a.x == b.x && a.y == b.y && a.have == b.have);
	}
};
class hash_node {
public:
	size_t operator() ( const node a ) const
	{
		return(a.x + a.y + a.have);
	}
};
int d[50000005];
int	ma[55][55];
int	squ[55][55];
int get(int x,int y,int a,int b){
	return squ[a][b]-squ[x-1][b]-squ[a][y-1]+squ[x-1][y-1]+2500000;
}
int main()
{
	freopen( "horse.in", "r", stdin );
	freopen( "horse.out", "w", stdout );
	int n = read();
	for ( int i = 1; i <= n; i++ )
	{
		for ( int j = 1; j <= n; j++ )
		{
			ma[i][j] = read();
			squ[i][j]=squ[i][j-1]+ma[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			squ[i][j]+=squ[i-1][j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			{
				for(int n1=1;n1<=i;n1++){
					for(int m1=1;m1<=j;m1++){//左上右下
						d[get(n1,m1,i,j)]++;
					}
				}
				for(int n1=i+1;n1<=n;n1++){
					for(int m1=j+1;m1<=n;m1++){
						ans+=d[get(i+1,j+1,n1,m1)];
					}
				}
				for(int n1=1;n1<=i;n1++){
					for(int m1=1;m1<=j;m1++){//左上右下
						d[get(n1,m1,i,j)]--;
					}
				}
			}
			{
				for(int k=i;k<=n;++k)
					for(int l=1;l<=j;++l)
						++d[get(i,l,k,j)];
				for(int k=1;k<i;++k)
					for(int l=j+1;l<=n;++l)
						ans+=d[get(k,j+1,i-1,l)];
				for(int k=i;k<=n;++k)
					for(int l=1;l<=j;++l)
						d[get(i,l,k,j)]=0;
				}
		}
	}
	printf("%d",ans);
	return(0);
}


/*
 * Anything about this program:
 * Type:
 *
 * Description:
 *
 * Example:
 * 1:
 * In:
 *
 * Out:
 * More:
 *
 */


