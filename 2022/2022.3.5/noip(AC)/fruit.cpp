/*
ѡ��С��2�ѹ��Ӻϲ� 
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int>q;//���ȶ���ѡ�� 
int main(){
	freopen("fruit.in","r",stdin);
	freopen("fruit.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		q.push(-temp);//����-1��֤��С���� 
	}
	int ans=0;
	while(q.size()>1){//֪��ֻ��һ�ѹ��� 
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

