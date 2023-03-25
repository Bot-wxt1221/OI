#include <cstdio>
using namespace std;
int main(){
    int a,b,c,d,e,f,g;
    scanf("%d:%d:%d\n%d:%d:%d\n%d",&a,&b,&c,&d,&e,&f,&g);
    unsigned long long n=(d-a)*3600+(e-b)*60+(f-c);
    n=n*g;
    printf("%d",n);
    return 0;
}
