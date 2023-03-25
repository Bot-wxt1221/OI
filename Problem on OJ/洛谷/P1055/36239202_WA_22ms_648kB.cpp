#include <cstdio>
using namespace std;
int a[10];
int main(){
    a[0]=getchar()-'0';
    getchar();
    a[1]=getchar()-'0';
    a[2]=getchar()-'0';
    a[3]=getchar()-'0';
    getchar();
    a[4]=getchar()-'0';
    a[5]=getchar()-'0';
    a[6]=getchar()-'0';
    a[7]=getchar()-'0';
    a[8]=getchar()-'0';
    getchar();
    a[9]=getchar()-'0';
    if(a[9]==(a[0]*1+a[1]*2+a[2]*3+a[3]*4+a[4]*5+a[5]*6+a[6]*7+a[7]*8+a[8]*9)){
        printf("Right");
    }else{
        a[9]==(a[0]*1+a[1]*2+a[2]*3+a[3]*4+a[4]*5+a[5]*6+a[6]*7+a[7]*8+a[8]*9);
        printf("%d-%d%d%d-%d%d%d%d%d-%d",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
    }
    return 0;
}