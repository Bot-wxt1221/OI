/*
   ����˼·���������ϡ����ϡ����¡����º���һ�ȼ��ᡢ������֮��Ĺ�ϵ���������ϵĺ����������һ�ȼ��������꣬
   ���ϵ������������һ�ȼ��ĺ����꣬�������ƹ�ϵ��

	ע��㣺 
	1�����ݽϴ󣬲���long long���ݵ�Ԫ 
	2�������Ҫ�������룬����round����
*/

#include<cstdio>  
#include<cmath>  
long long am[5][2]={{0,0},{0,0},{0,1},{1,1},{1,0}};     //���1������; 2:��������3����������4��һ��ӣ�  
long long n,a,b,N,x1,x2,y3,y2;  
void ml(long long l,long long x,long long &y,long long &z)  
{  
    long long ax = y, bx = z;  
    if(l == 1)   //����1�����϶Խ��߷���  
    {  
        y = bx;  
        z = ax;  
    }  
    if(l == 4)    //����4�����϶Խ��߷���  
    {  
        long long k = pow(2,x);   //���и��ӱ߳���һ��  
        y = bx;  
        z = ax;  
        y = k-y-1;    //ע���һ  
        z = k-z-1;  
    }  
}  
void mzls(long long l,long long x,long long &y,long long &z)  
{  
    if(l == 0)    return;  
    long long k = pow(2,2*(l-1)),i;  
    for(i = 1; i <= 4; i++)   //�жϿ�������ţ�1  2  
        if(k*i >= x)                          //4  3  
            break;  
    mzls(l-1,x-(i-1)*k,y,z);  //�ֳ���һ��  
    ml(i,l-1,y,z);  
    y += pow(2,l-1) * am[i][0];    //��ͬ����������ı�  
    z += pow(2,l-1) * am[i][1];  
}  
int main()  
{  
    freopen("stupid.in","r",stdin);
    freopen("stupid.out","w",stdout);
	
	scanf("%lld",&N);  
    for(int i = 1; i <= N; i++)  
    {  
        scanf("%lld%lld%lld",&n,&a,&b);  
        x1 = x2 = y3 = y2 = 0;  
        mzls(n,a,x1,x2);  
        mzls(n,b,y3,y2);  
        long long ans = round(sqrt(pow((x1-y3)*10,2)+pow((x2-y2)*10,2)));      //��ѧ��ʽ�������  
        printf("%lld\n",ans);  
    }
}
