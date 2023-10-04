#include <iostream>
#include <cstdio>
#include <set>
#define int unsigned long long
using namespace std;
int read(){
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
multiset <int>bigger;
multiset<int> small;
signed main(){
	freopen("average.in","r",stdin);
	freopen("average.out","w",stdout);
	int n1,n2,n;
	n1=read();
	n2=read();
	n=read();
	while(!(n1==0&&n2==0&&n==0)){
		int total=0;
		small.clear();
		bigger.clear();
		for(int i=1;i<=n;i++){
			int temp=read();
			total+=temp;
			if(bigger.size()<n1){
				bigger.insert(temp);
			}else{
				if(*bigger.begin()<temp){
					bigger.erase(bigger.begin());
					bigger.insert(temp);
				}
			}
			if(small.size()<n2){
				small.insert(temp);
			}else{
				multiset<int>::iterator a=small.end();
				a--;
				if(*a>temp){
					small.erase(a);
					small.insert(temp);
				}
			}
		}
		multiset<int>::iterator a=bigger.begin();
		for(int i=0;i<bigger.size();i++){
			total-=*a;
			a++;
		}
		a=small.begin();
		for(int i=0;i<small.size();i++){
			total-=*a;
			a++;
		}
		printf("%.6lf\n",double(total)/(n-n1-n2));
		n1=read();
		n2=read();
		n=read();
	}
	return 0;
}
/*
Anything about this program:
Type:
	例题 
Description:
	在演讲比赛中，当参赛者完成演讲时，法官将对他的表现进行评分。工作人员去掉最高分和最
低分，取其余分数的平均值作为参赛者的最终成绩。这是一个简单的问题，因为通常只有几个
法官。
让我们考虑上述问题的一般形式。给定n 个正整数，删除最大的n 
1
个和最小的n 
2
个，并计算
其余的平均值。
Example:
	1:
		In:	
			1 2 5
			1 2 3 4 5
			4 2 10
			2121187 902 485 531 843 582 652 926 220 155
			0 0 0
		Out:
			3.500000
			562.500000
More:
维护需要的极值 set效率较低 
*/

