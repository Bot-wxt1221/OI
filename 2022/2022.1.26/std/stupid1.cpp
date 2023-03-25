/*
   解题思路：利用左上、右上、左下、右下和上一等级横、纵坐标之间的关系，比如左上的横坐标等于上一等级的纵坐标，
   左上的纵坐标等于上一等级的横坐标，建立递推关系。

	注意点： 
	1、数据较大，采用long long数据单元 
	2、结果需要四舍五入，调用round函数
*/

#include<cstdio>  
#include<cmath>  
long long am[5][2]={{0,0},{0,0},{0,1},{1,1},{1,0}};     //标号1：不变; 2:加列数；3：加行数；4：一起加；  
long long n,a,b,N,x1,x2,y3,y2;  
void ml(long long l,long long x,long long &y,long long &z)  
{  
    long long ax = y, bx = z;  
    if(l == 1)   //块数1：左上对角线翻折  
    {  
        y = bx;  
        z = ax;  
    }  
    if(l == 4)    //块数4：右上对角线翻折  
    {  
        long long k = pow(2,x);   //行列各加边长的一半  
        y = bx;  
        z = ax;  
        y = k-y-1;    //注意减一  
        z = k-z-1;  
    }  
}  
void mzls(long long l,long long x,long long &y,long long &z)  
{  
    if(l == 0)    return;  
    long long k = pow(2,2*(l-1)),i;  
    for(i = 1; i <= 4; i++)   //判断块数（标号）1  2  
        if(k*i >= x)                          //4  3  
            break;  
    mzls(l-1,x-(i-1)*k,y,z);  //分成下一级  
    ml(i,l-1,y,z);  
    y += pow(2,l-1) * am[i][0];    //不同块数行列需改变  
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
        long long ans = round(sqrt(pow((x1-y3)*10,2)+pow((x2-y2)*10,2)));      //数学公式计算距离  
        printf("%lld\n",ans);  
    }
}
