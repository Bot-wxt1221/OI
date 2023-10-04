/*熄灯问题： 
通过深搜确定第一行的答案状态，依次推出其他灯的状态，再判断合理性，即推出答案 
*/
#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
bool ans[10][10];//答案 
const int pre[5][2]={{0,1},{0,-1},{1,0},{-1,0},{0,0}};//五个方向 
bool a[10][10];//状态 
int puz;//案例序号 
void dfs(int step);
signed main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	ios::sync_with_stdio(false);//使用这行加速输入后，不能用printf（qwq） 
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		puz=i; 
		memset(ans,0,sizeof(ans));//清空ans数组 
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
		int a[10][10];//内部数组下面访问的是这个数组 
		for(int i=1;i<=5;i++){
			for(int j=1;j<=6;j++){
				a[i][j]=::a[i][j];//复制数值 
			}
		}
		for(int i=1;i<=6;i++){
			for(int j=0;j<5;j++){
				if(ans[1][i])
				a[1+pre[j][0]][i+pre[j][1]]^=1;//初始化第一排 
			}
		}
		for(int i=2;i<=5;i++){//如果上面的灯亮着，按下这一排的灯想要熄灭上面的灯，就必须按这个 
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
	ans[1][step+1]=0;//枚举按下或没按下 
	dfs(step+1);
	ans[1][step+1]=1;
	dfs(step+1);
	ans[1][step+1]=0;
	return ;
}
