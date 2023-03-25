/*
   RMQ + 二分
题意：
   给你多组year,rainfall
   多组查询，Y、X，查询[Y,X]区间是否满足Y是最大降雨量的要求
   (1)降雨量X>=Y
   (2)[Y-1,X-1]降雨量都已知且严格小于X
   (3)X、Y降雨量已知
   满足的输出true,不满足输出false,可能满足的输出maybe
思路：
   之前的都是直接告诉你区间下标，这道题需要自己找，二分查找lower_bound>=key的元素
   然后分情况讨论，不同情况下RMQ()的区间还有区别
   注意RMQ()中L>R的情况，返回的值尽可能的小<-10^9（因为找的是区间最大值）   
*/
#include<iostream>
#include<cstdio>
#define INF 0x7fffffff
#define inf -INF

using namespace std;
const int _max = 5e4 + 10;
 
int d[_max][20], a[_max], b[_max];
 
int n, Q;
 
void RMQ_init(){
  for(int i = 0; i < n; ++ i) d[i][0] = b[i];//降雨量
  for(int j = 1; (1<<j)<=n; ++j)
  for(int i = 0; i + (1<<j)-1 < n; ++ i){
     d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
  }
}
 
int RMQ(int L, int R){
  if(L>R) return inf;//最小值<-10^9
  int k = 0;
  while((1<<(k+1)) <= R-L+1) ++k;
  return max(d[L][k], d[R-(1<<k)+1][k]);
}
 
int main()
{
   
//   freopen("worstweather.in", "r", stdin);
//   freopen("worstweather.out", "w", stdout);
   int cnt = 0;
   while(scanf("%d",&n) == 1){
   // memset(a,inf,sizeof(a));
    for(int i = 0; i < n; ++ i) scanf("%d%d", a+i, b+i); 
    scanf("%d", &Q); 
	if(Q+n == 0) break;
    if(cnt) puts(""); else cnt++;
    int Y, X;
    RMQ_init();
    while(Q--){
        scanf("%d%d", &Y, &X);
        int l = lower_bound(a, a+n, Y) - a;
        int r = lower_bound(a, a+n, X) - a;
        int t;
        if(a[l]!=Y && a[r]!=X) puts("maybe");    
		else if(a[l]==Y && a[r]==X){   
            if(b[l] < b[r]) puts("false");
            else{
                t = RMQ(l+1, r-1);
                if(t < b[r]){
                    if(r-l+1 == X-Y+1) puts("true");
                    else puts("maybe");
                }
                else puts("false");
            }
        }
        else if(a[l]==Y && a[r]!=X){
          t = RMQ(l+1, r-1);
          if(t>=b[l]) puts("false");
          else puts("maybe");
        }
        else{
           t = RMQ(l, r-1);
           if(t>=b[r]) puts("false");
           else puts("maybe");
        }
    }
   }
   fclose(stdin);
   fclose(stdout);
   return 0;
}

