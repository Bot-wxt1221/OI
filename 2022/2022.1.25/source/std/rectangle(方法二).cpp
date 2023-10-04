//矩形分割 
#include <iostream>
#include <cstdio>
using namespace std;
//x1 储存小矩形左上角坐标  x2  存小矩形右上角坐标   y1  小矩形左上角纵坐标值   w, h, s , 分别为  宽度，长度，高度 
long long x1[10005],x2[10005],y1[10005],w[10005],h[10005],s[10005];    
long long R,N,ans;
long long f(long long x);     //运算函数  运算左右两边相差面积 
void work(long long l,long long r);     //二分函数   进行二分递归运算 

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

long long f(long long x)     //运算函数  运算左右两边相差面积 
{
	long long sum = 0;
	for(long long i = 1; i <= N; i++)         //面积运算  分别为   全在左  全在右  在中间
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
 
 void work(long long l,long long r)     //二分函数   进行二分递归运算 
 {
     if(l == r)    //边界值  返回条件 
	 {     
         ans=l;
         return ;
     }
     long long mid = (l + r) / 2;
     if( f(mid) >= 0 ) work(l,mid);      //二分递归 
     else work(mid+1,r);
 }
