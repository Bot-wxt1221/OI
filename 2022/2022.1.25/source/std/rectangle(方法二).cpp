//���ηָ� 
#include <iostream>
#include <cstdio>
using namespace std;
//x1 ����С�������Ͻ�����  x2  ��С�������Ͻ�����   y1  С�������Ͻ�������ֵ   w, h, s , �ֱ�Ϊ  ��ȣ����ȣ��߶� 
long long x1[10005],x2[10005],y1[10005],w[10005],h[10005],s[10005];    
long long R,N,ans;
long long f(long long x);     //���㺯��  ������������������ 
void work(long long l,long long r);     //���ֺ���   ���ж��ֵݹ����� 

int main(void)
{
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	
	cin >> R;
    cin >> N;
    for(long long i = 1; i <= N; i++)
	{
        cin >> x1[i] >> y1[i] >> w[i] >>h[i];
        x2[i] = x1[i] + w[i];
        s[i] = w[i] * h[i];
    }
    work(0,R);
    while( f(ans) == f(ans+1) && ans < R ) ans++;
    cout<<ans<<endl;
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

long long f(long long x)     //���㺯��  ������������������ 
{
	long long sum = 0;
	for(long long i = 1; i <= N; i++)         //�������  �ֱ�Ϊ   ȫ����  ȫ����  ���м�
	{    
		if(x2[i]<=x)
		{
            sum+=s[i];
			continue; 
		}
		else if(x1[i]>=x)
		{
            sum-=s[i];
			continue;
        }
        else 
            sum=sum+(x-x1[i])*h[i]-(x2[i]-x)*h[i];         
    }
    return sum;
 }
 
 void work(long long l,long long r)     //���ֺ���   ���ж��ֵݹ����� 
 {
     if(l == r)    //�߽�ֵ  �������� 
	 {     
         ans=l;
         return ;
     }
     long long mid = (l + r) / 2;
     if( f(mid) >= 0 ) work(l,mid);      //���ֵݹ� 
     else work(mid+1,r);
 }
