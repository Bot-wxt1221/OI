/*
������ʱ������
�ٴ�С�����ж��Ƿ��ͻ 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class node{
	public:
		int s,e;
}a[505];
bool cmp(node a,node b){
	return (a.e-a.s)<(b.e-b.s);
}
vector<node>use;
int main(){
	freopen("meeting.in","r",stdin);
	freopen("meeting.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].e;
	}
	sort(a+1,a+n+1,cmp);//������ʱ������ 
	int ans=0;
	for(int i=1;i<=n;i++){
		int can=1;
		for(int j=0;j<use.size();j++){//�����ж��Ƿ��ͻ 
			if(a[i].e<=use[j].s||a[i].s>=use[j].e){
			}else{
				can=0;
			}
		}
		if(can){
			ans++;
		 	use.push_back(a[i]);
		}
	}
	cout<<n-ans;
	return 0;
}
