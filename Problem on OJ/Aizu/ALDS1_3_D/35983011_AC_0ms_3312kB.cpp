#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
 
 
 
stack<int> s1;
 
struct Node
{
	int left;
	int area;
	Node(int l,int a)
	{
		left=l;
		area=a;
	}
};
vector<Node> v;//保存各区域面积
 
int main()
{
//	freopen("areas.in","r",stdin);
//	freopen("2.out","w",stdout);
	string S;
	cin>>S;
	int sum=0;//字符串长度最大20000，则最大面积 < 2*10^8
	for(unsigned int i=0; i<S.length(); i++)
	{
		if(S[i]=='\\')//注意‘\ ’的表示方法
		{
			s1.push(i);
		}
		if(S[i]=='/'&&!s1.empty())
		{
			int j=s1.top();
			s1.pop();
			sum+=i-j;
			int a=i-j;
			while(!v.empty()&&v.back().left>j)
			{
				a+=v.back().area;
				v.pop_back();
			}
 
			v.push_back(Node(j,a));
		}
	}
	cout<<sum<<endl;
	cout<<v.size();
	for(unsigned int i=0; i<v.size(); i++)
	{
		cout<<" "<<v[i].area;
	}
	cout<<endl;
	return 0;
}