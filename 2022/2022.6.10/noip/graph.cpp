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
	���� 
Description:
	ȡ�κξ��� n ������� m ���ߵ�����ͼ D��������ͨ�����·�ʽ���� D �� Lying graph E��E ����
m �����㣬һ�������Ӧ�� D ��ÿ���ߡ����磬��� D ��һ����uv����ô E ����һ����Ϊuv�Ķ��㡣
���ڣ�ֻҪ D �б�uv��vw��E �ͻ���һ���Ӷ���uv������vw�ıߡ�E ��û�������ߡ����ȷ�� E �Ƿ�
������ĳ������ͼ D �� Lying graph��
Example:
	1:
		In:
			graph1.in
		Out:
			graph1.out
More:
	��תվ 
*/


