#include <cstdio>
using namespace std;
int main(){
    int a,b,c,d,e,f,g;
    printf("%d:%d:%d\n%d:%d:%d\n%d",&a,&b,&c,&d,&e,&f,&g);
    long long n=(d-a)*3600+(e-b)*60+(f-c);
    n=n*g;
    cout<<n;
    return 0;
}