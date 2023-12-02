#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define int long long
inline int read();
class node{
    public:
        int x,y,i;
}Map[105],Map2[105],Map3[105];
bool cmp1(node a,node b){
    return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmp2(node a,node b){
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
int left[105],a[105],b[105];
std::map<int,int> m1ap;
std::map<int,int> m1ap2;
signed main(){
    // freopen("in.in","r",stdin);
    // freopen("2.out","w",stdout);
    int n;
    int case1=0;
    while(scanf("%lld",&n)!=EOF){
        if(n==0){
            return 0;
        }
        m1ap.clear();
        m1ap2.clear();
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%lld",&a);
            scanf("%lld",&b);
            Map[i].x=Map2[i].x=a;
            Map[i].y=Map2[i].y=b;
            Map[i].i=Map2[i].i=i;
        }
        std::sort(Map+1,Map+1+n,cmp1);
        std::sort(Map2+1,Map2+1+n,cmp2);
        int ans=0;
        int to=0;
        int to2=0;
        int tmp1=0,tmp2=0;
        for(int i=1;i<=n;i++){
            if(m1ap.find(Map[i].x)!=m1ap.end()){
                Map[i].x=Map[i-1].x;
                Map3[Map[i].i].x=Map[i].x;
            }else{
                m1ap.insert(std::pair<int,int>(Map[i].x,++tmp1));
                Map[i].x=tmp1;
                Map3[Map[i].i].x=Map[i].x;
            }
            if(m1ap2.find(Map2[i].y)!=m1ap2.end()){
                Map2[i].y=Map2[i-1].y;
                Map3[Map2[i].i].y=Map2[i].y;
            }else{
                m1ap2.insert(std::pair<int,int>(Map2[i].y,++tmp2));
                Map2[i].y=tmp2;
                Map3[Map2[i].i].y=Map2[i].y;
            }
        }
        if(tmp1<=2||tmp2<=2){
            printf("Case %lld: %lld\n",++case1,n);
            continue;
        }
        for(int i=1;i<=n;i++){
            Map[i].x=Map2[i].x=Map3[i].x;
            Map[i].y=Map2[i].y=Map3[i].y;
            Map[i].i=Map2[i].i=i;
        }
        std::sort(Map+1,Map+1+n,cmp1);
        std::sort(Map2+1,Map2+1+n,cmp2);
        for(int i=1;i<=tmp2;i++){
            for(int j=i+1;j<=tmp2;j++){
                memset(left,0,sizeof(left));
                memset(a,0,sizeof(a));
                memset(b,0,sizeof(b));
                int m=-0x3f3f3f3f3f3f3f3fll;
                int mm=1;
                for(int kkk=1;kkk<=tmp1+1;kkk++){
                    left[kkk]+=left[kkk-1];
                    while(mm<=n&&Map[mm].x==kkk){
                        if(Map[mm].y==i){
                            left[kkk+1]++;
                            b[kkk]++;
                        }
                        if(Map[mm].y==j){
                            left[kkk+1]++;
                            b[kkk]++;
                        }
                        if(i<Map[mm].y&&Map[mm].y<j){
                            a[kkk]++;
                            b[kkk]++;
                        }
                        mm++;
                    }
                    ans=std::max(ans,left[kkk]+b[kkk]+m);
                    m=std::max(m,a[kkk]-left[kkk]);
                }
            }
        }
        printf("Case %lld: %lld\n",++case1,ans);
    }
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


