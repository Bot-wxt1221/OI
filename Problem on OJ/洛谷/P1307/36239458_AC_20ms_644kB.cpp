#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100],c[100];
int main()
{
      int n,l;
      cin>>n;
      sprintf(s,"%d",n);
      l=strlen(s);
      for (int i=0; i<=l-1; ++i)  c[l-i-1]=s[i];
      if (n<0) cout<<"-";
      sscanf(c,"%d",&n);
      cout<<n;
      return 0;
}
