#include <bits/stdc++.h>
using namespace std;
double a,b,c;
double count[10];
double f(double x){
    return x*x*x*a+x*x*b+x*c+d;
}
int main(){
    int n=0;
    for (double i=-100;i<=100;i+=0.01){
        int x=i;xx=i+1;
        if(abs(f(x)*f(xx))<1E-5){
            count[++i]=x;
        }
    }
    sort(count+1,count+4);
    printf("%.2f %.2f %.2f",count[1],count[2],count[3]);
    return 0;
}