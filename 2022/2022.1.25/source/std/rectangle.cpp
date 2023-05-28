#include <cstdio>
#include <cmath>
using namespace std;
struct obj
{
     long long left,top,w,h;      //左上角横、纵坐标和宽、高值
     long long rx;                //右下角顶点的横坐标 
     long long s;                 //面积 
};
long long sigema(struct obj a[],int n,int mid)
{
     int i;
     long long sum1,sum2;
     sum1 = sum2 = 0;
     for(i = 0; i < n; i++)
     {
         if(a[i].rx <= mid) sum1 += a[i].s;           //该矩形属左侧
         else if(a[i].left >= mid) sum2 += a[i].s;        //属右侧
         else
         {
             sum1 += a[i].h * (mid - a[i].left);
             sum2 += a[i].h * (a[i].rx - mid);
         }
     }
     return sum1-sum2;
 }
 int main(void)
 {
     long long r,n,i;
     struct obj a[10005];
     long long minx,maxx,mid,ans,maxx2;
     long long temp,temp1,temp2;
     freopen("rectangle.in","r",stdin);
     freopen("rectangle.out","w",stdout);
     scanf("%lld%lld",&r,&n);
     for(i = 0; i < n; i++) 
     {
         scanf("%lld%lld%lld%lld",&a[i].left,&a[i].top,&a[i].w,&a[i].h);
         a[i].s = a[i].w * a[i].h;
         a[i].rx = a[i].left + a[i].w;
         if(i == 0)  maxx2 = a[i].rx;
         else
         {
             if(a[i].rx > maxx2) maxx2 = a[i].rx;
         }
     }
     minx = 0;
     maxx = r;
     while(minx + 1 < maxx)      //需要二分枚举的答案是整数，所以可以用这个方式结束 
     {
         mid = (minx + maxx) / 2;
         temp = sigema(a,n,mid);
         if(temp > 0) maxx = mid;
         else if(temp <= 0) minx = mid;
     }
     
     temp1 = sigema(a,n,minx);
     temp2 = sigema(a,n,maxx);
     /*if(fabs(temp1)<fabs(temp2)) ans=minx;
58     else ans=maxx;*/
     if( temp1 < temp2)
     {
         if(temp1 >= 0) ans = minx;
         else ans = maxx;
     }
     else if(temp1 > temp2)
     {
         if(temp2 >= 0) ans = maxx;
         else ans = minx;
     }
     else ans = maxx;
     if(ans == maxx2) ans = r;
     printf("%lld\n",ans);
    
	 fclose(stdin);
     fclose(stdout);
     return 0;
 }
