/*
选最小的2堆果子合并 
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int>q;//优先队列选数 
int main(){
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		q.push(-temp);//乘上-1保证是小根堆 
	}
	int ans=0;
	while(q.size()>1){//知道只有一堆果子 
		int a=-q.top();
		q.pop();
		int b=-q.top();
		q.pop();
		ans+=(a+b);
		q.push(-a-b);
	}
	cout<<ans;
	return 0;
}

