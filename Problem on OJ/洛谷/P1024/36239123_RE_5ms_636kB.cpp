#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double cont[10];
double f(double x){
    return x*x*x*a+x*x*b+x*c+d;
}
int main(){
    cin>>a>>b>>c>>d;
    int n=0;
    for (double i=-100;i<=100;i+=0.01){
        int x=i,xx=i+1;
        if(abs(f(x)*f(xx))<1E-5){
            cont[++n]=x;
        }
    }
    sort(cont+1,cont+4);
    printf("%.2f %.2f %.2f",cont[1],cont[2],cont[3]);
    return 0;
}