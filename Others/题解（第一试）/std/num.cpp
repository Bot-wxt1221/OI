#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int mod=100000003;
int a[1005];
int b[1005];
long long sum(int l,int r)
{
	long long ans=0;
	while (l<=r)
	{
		ans+=a[l];
		l++;
	}
	return ans;
}
void _plus(int l,int r,int x)
{
	while (l<=r)
	{
		a[l]+=x;
		a[l]%=mod;
		l++;
	}
	return ;
}
int k_max(int l,int r,int k)
{
	if ((r-l+1)<k||k<=0) return -1;
	int t=0;
	while (l<=r)
	{
		t++;
		b[t]=a[l];
		l++;
	}
	sort(b+1,b+t+1);
	return b[t-k+1];
}
int k_min(int l,int r,int k)
{
	if ((r-l+1)<k||k<=0) return -1;
	int t=0;
	while (l<=r)
	{
		t++;
		b[t]=a[l];
		l++;
	}
	sort(b+1,b+t+1);
	return b[k];
}
void oppo(int l,int r)
{
	while (l<=r)
	{
		swap(a[l],a[r]);
		l++;
		r--;
	}
	return ;
}
void Swap(int l,int r,int l2,int r2)//�����Ƚ�[L2,R2]������Ȼ����[R,L2]��Ȼ����[L,R]��������帳ֵ��ȥ������ 
{
	int t=l;
	for (int i=l2;i<=r2;i++)
		b[t++]=a[i];
	for (int i=r+1;i<l2;i++)
		b[t++]=a[i];
	for (int i=l;i<=r;i++)
		b[t++]=a[i];
	for (int i=l;i<t;i++)
		a[i]=b[i];
	return ;
}
void out(int l,int r)
{
	while (l<=r)
	{
		cout<<a[l]<<" ";
		l++;
	}
	cout<<endl;
	return ;
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=mod;
	}
	for (int i=1;i<=m;i++)
	{
		int type,l,r,x,l2,r2;
		cin>>type;
		if (type==1)//����� 
		{
			cin>>l>>r;
			printf("%lld\n",sum(l,r));
		} 
		else if (type==2)//�����޸� 
		{
			cin>>l>>r>>x;
			_plus(l,r,x);
		}
		else if (type==3)//k�� 
		{
			cin>>l>>r>>x;
			printf("%d\n",k_max(l,r,x));
		}
		else if (type==4)//kС 
		{
			cin>>l>>r>>x;
			printf("%d\n",k_min(l,r,x));
		}
		else if(type==5)//��ת 
		{
			cin>>l>>r;
			oppo(l,r);
		}
		else  if (type==6)//���� 
		{
			cin>>l>>r>>l2>>r2;
			if (r2<l)
			{
				swap(l,l2);
				swap(r,r2);
			}
			Swap(l,r,l2,r2);
		}
		else//������� 
		{
			cin>>l>>r;
			out(l,r);
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
