/*Ϩ�����⣺ 
ͨ������ȷ����һ�еĴ�״̬�������Ƴ������Ƶ�״̬�����жϺ����ԣ����Ƴ��� 
*/
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
bool ans[10][10];//�� 
const int pre[5][2]={{0,1},{0,-1},{1,0},{-1,0},{0,0}};//������� 
bool a[10][10];//״̬ 
int puz;//������� 
void dfs(int step);
signed main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	ios::sync_with_stdio(false);//ʹ�����м�������󣬲�����printf��qwq�� 
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		puz=i; 
		memset(ans,0,sizeof(ans));//���ans���� 
		for(int j=1;j<=5;j++){
			for(int m=1;m<=6;m++){
				cin>>a[j][m];
			}
		}
		dfs(0);
	}
	return 0;
}
void dfs(int step){
	if(step==6){
		int a[10][10];//�ڲ�����������ʵ���������� 
		for(int i=1;i<=5;i++){
			for(int j=1;j<=6;j++){
				a[i][j]=::a[i][j];//������ֵ 
			}
		}
		for(int i=1;i<=6;i++){
			for(int j=0;j<5;j++){
				if(ans[1][i])
				a[1+pre[j][0]][i+pre[j][1]]^=1;//��ʼ����һ�� 
			}
		}
		for(int i=2;i<=5;i++){//�������ĵ����ţ�������һ�ŵĵ���ҪϨ������ĵƣ��ͱ��밴��� 
			for(int j=1;j<=6;j++){
				ans[i][j]=0;
				if(a[i-1][j]){
					ans[i][j]=1;
					for(int m=0;m<5;m++){
						a[i+pre[m][0]][j+pre[m][1]]^=1;
					}
				}
			}
		}
		for(int i=1;i<=6;i++){
			if(a[5][i]){
				return ;
			}
		}
		cout<<"PUZZLE #"<<puz<<endl;
		for(int i=1;i<=5;i++){
			for(int j=1;j<=6;j++){
				cout<<ans[i][j]<<' ';
			}
			cout<<endl;
		}
		return ;//qwq 
	}
	ans[1][step+1]=0;//ö�ٰ��»�û���� 
	dfs(step+1);
	ans[1][step+1]=1;
	dfs(step+1);
	ans[1][step+1]=0;
	return ;
}
