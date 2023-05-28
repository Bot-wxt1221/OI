#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
string s;
int a[100];
int main(){
	while(1){
		cin>>s;
		if(s=="END")
			break;
		memset(a,0,sizeof(a));
		int n=s.size();
		for(int i=0;i<n;i++)
			if(s[i]=='_')
				a[26]++;
			else
				a[s[i]-'A']++;
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=0;i<=26;i++)
			if(a[i])
				q.push(a[i]);
		int ans=n;
		while(q.size()>2){
			int t,t1,t2;
			t1=q.top(),q.pop();
			t2=q.top(),q.pop();
			t=t1+t2;
			ans+=t;
			q.push(t);
		}
		printf("%d %d %.1lf\n",n*8,ans,(double)n*8/ans);
	}
	return 0;
}

