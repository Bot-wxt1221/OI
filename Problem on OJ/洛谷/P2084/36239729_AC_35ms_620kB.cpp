#include<cstdio>
#include<cstring>
using namespace std;
int m;
char c[1001];
int main()
{
    scanf("%d ",&m);
    gets(c);
    for (int i=0;i<strlen(c);i++)    
    {
     if(i!=0&&c[i]!='0') printf("+");
     if (c[i]=='0') continue;
      printf("%c*%d^%d",c[i],m,strlen(c)-i-1);
    }
}