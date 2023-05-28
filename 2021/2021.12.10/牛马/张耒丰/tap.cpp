#include <cstdio>
#include<iostream>
using namespace std;
int n;
long long int f[100];
void dfs();
int main()
{
	
    freopen("tap.in","r",stdin);
    freopen("tap.out","w",stdout);
    
    cin>>n;
    if(n==1)
    {
    	printf("1");
    	return 0;
    }
    
    f[n]=1;
    for(int i=n-1;i>=1;i--)
    {
    	f[i]=f[i+1]+f[i+2]+f[i+2]+f[i+4]+f[i+6];
	}	
   	
   	cout<<f[1]-(n-3)*(n-3);
    fclose(stdin);
    fclose(stdout);
    
	return 0;
}


