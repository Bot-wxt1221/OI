//g++  7.4.0

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int w;
    scanf("%d",&w);
    sort(a+1,a+n+1);
    if(n==0||a[1]>w){
        printf("0");
        return 0;
    }
    int temp=upper_bound(a+1,a+n+1,w)-a-1;
    int more=a[temp];
    for(int i=1;i<temp;i++){
        more-=a[i];
        if(more<0){
            printf("%d",max(i-1,1));
            return 0;
        }
    }
    printf("%d",max(1,temp-1));
    return 0;
}