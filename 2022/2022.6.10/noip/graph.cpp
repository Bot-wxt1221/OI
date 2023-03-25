#include <iostream>
#include <cstdio>
using namespace std;
bool map[605][605];
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	ios::sync_with_stdio(false);
	int NN;
	scanf("%d",&NN);
	for(int N=1;N<=NN;N++){
		memset(map,0,sizeof(map));
		printf("Case #%d: ",N);
		int m;
		int k;
		scanf("%d%d",&m,&k);
		for(int i=1;i<=k;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			map[a][b]=1;
		}
		int yes=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				bool f1=0,f2=0;
				for(int aa=0;aa<m;aa++){
					if(map[i][aa]&&map[j][aa])	f1=1;
					if(map[i][aa]^map[j][aa])	f2=1;
				}
				if(f1&&f2){
					yes=0;
					break;
				}
			}
		}
		if(yes){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	取任何具有 n 个顶点和 m 个边的有向图 D。您可以通过以下方式制作 D 的 Lying graph E。E 将有
m 个顶点，一个顶点对应于 D 的每条边。例如，如果 D 有一条边uv，那么 E 将有一个名为uv的顶点。
现在，只要 D 有边uv和vw，E 就会有一条从顶点uv到顶点vw的边。E 中没有其他边。编程确定 E 是否
可能是某个有向图 D 的 Lying graph。
Example:
	1:
		In:
			graph1.in
		Out:
			graph1.out
More:
	中转站 
*/


