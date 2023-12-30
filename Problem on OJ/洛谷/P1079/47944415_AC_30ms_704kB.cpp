#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
namespace pro{
  inline int read();
  char temp[105];
  char temp2[1005];
  int solve(){
    scanf("%s",temp);
    scanf("%s",temp2);
    int siz1=strlen(temp);
    int siz2=strlen(temp2);
    for(int i=0;i<siz1;i++){
      if('a'<=temp[i]&&temp[i]<='z'){
        temp[i]=temp[i]-'a'+'A';
      }
    }
    for(int i=0;i<siz2;i++){
      char base;
      if('a'<=temp2[i]&&temp2[i]<='z'){
        temp2[i]=temp2[i]-'a'+'A';
        base='a';
      }else{
        base='A';
      }
      char tem=-temp[i%siz1]+'A';
      tem+=(temp2[i]-'A');
      tem%=26;
      tem+=26;
      tem%=26;
      printf("%c",tem+base);
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


