//写不来这道题的人，多半就是废了  （昨天讲过）   递归解决 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
double dfs(){
	string a;
	cin>>a;
	switch(a[0]){
		case '+':return dfs()+dfs();
		case '-':return dfs()-dfs();
		case '*':return dfs()*dfs();
		case '/':return dfs()/dfs();
		default: return atof(a.c_str()); //string.c_str()是返回string类型的C风格字符串起始地址（数组名也是地址） 
	}
}
int main(){
	freopen("expression.in","r",stdin);
	freopen("expression.out","w",stdout);
	printf("%.6lf",dfs());//精度控制 
	return 0;
}

