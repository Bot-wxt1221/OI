/*
   RMQ + ����
���⣺
   �������year,rainfall
   �����ѯ��Y��X����ѯ[Y,X]�����Ƿ�����Y�����������Ҫ��
   (1)������X>=Y
   (2)[Y-1,X-1]����������֪���ϸ�С��X
   (3)X��Y��������֪
   ��������true,���������false,������������maybe
˼·��
   ֮ǰ�Ķ���ֱ�Ӹ����������±꣬�������Ҫ�Լ��ң����ֲ���lower_bound>=key��Ԫ��
   Ȼ���������ۣ���ͬ�����RMQ()�����仹������
   ע��RMQ()��L>R����������ص�ֵ�����ܵ�С<-10^9����Ϊ�ҵ����������ֵ��   
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
  for(int i = 0; i < n; ++ i) d[i][0] = b[i];//������
  for(int j = 1; (1<<j)<=n; ++j)
  for(int i = 0; i + (1<<j)-1 < n; ++ i){
     d[i][j] = max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
  }
}
 
int RMQ(int L, int R){
  if(L>R) return inf;//��Сֵ<-10^9
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

