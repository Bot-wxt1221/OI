#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
inline int read();
std::vector<int>vec[7005];
void add(int x,int y){
    vec[x].push_back(y);
    return ;
}
int color[7005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    std::vector<int> tep;
    for(int i=1;i<=n;i++){
        int ci=read();
        tep.clear();
        for(int j=1;j<=ci;j++){
            int t=read();
            tep.push_back(t);
        }
        std::sort(tep.begin(),tep.end());
        vec[i].push_back(tep[0]);
        for(int j=1;j<ci;j++){
            if(tep[j]!=tep[j-1]){
                vec[i].push_back(tep[j]);
            }
        }
    }
    int cnt1=n,cnt2=0;
    int ccc=1;
    bool cccccccc=1;
    while(cccccccc){
        cccccccc=0;
        do{
            bool con=0;
            for(int i=1;i<=n;i++){
                if(color[i]==ccc){
                    continue;
                }
                int cnt=0;
                for(int j=0;j<vec[i].size();j++){
                    cnt+=(color[vec[i][j]]==color[i]);
                }
                if(cnt>1){
                    if(ccc){
                        cnt1--;
                        cnt2++;
                    }else{
                        cnt2--;
                        cnt1++;
                    }
                    color[i]=ccc;
                    con=1;
                    cccccccc=1;
                    break;
                }
            }
            if(con){
                continue;
            }
            break;
        }while(1);
        ccc^=1;
    }
    int lc;
    if(cnt1==cnt2){
        lc=color[1];
    }
    if(cnt1<cnt2){
        lc=0;
    }else{
        lc=1;
    }
    printf("%d\n",std::min(cnt1,cnt2));
    for(int i=1;i<=n;i++){
        if(color[i]==lc){
            printf("%d ",i);
        }
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


