#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();

bool cmp2(char a,char b){
  return a>b;
}
namespace pro{
  char temp[3005];
  std::string str[3005];
  std::string str2[3005];
  inline int read();
  int solve(){
    int n=read(),m;
    m=read();
    std::string _min;
    for(int i=1;i<=n;i++){
      scanf("%s",temp+1);
      str[i]=std::string(temp+1);
      str2[i]=str[i];
      std::sort(str2[i].begin(),str2[i].end(),cmp2);
      std::sort(str[i].begin(),str[i].end());
      if(i==1){
        _min=str2[i];
      }else{
        _min=std::min(_min,str2[i]);
      }
    }
    for(int i=1;i<=n;i++){
      if(str[i]<=_min){
        printf("1");
      }else{
        printf("0");
      }
    }
    return 0; 
  }
};
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	return pro::solve();
}
inline int pro::read(){
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


