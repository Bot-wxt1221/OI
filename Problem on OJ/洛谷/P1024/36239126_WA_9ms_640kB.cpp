#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return x*x*x*a+x*x*b+x*c+d;
}
int main(){
    cin>>a>>b>>c>>d;
    int n=0;
    for (int i=-100;i<=100;i++){
        double x=i,xx=i+1;
        if(f(x)==0){
            printf("%.2f ",x);
        }
        if(f(x)*f(xx)<0){
            double mid;
            while(xx-x>0.001){
                mid=(x+xx)/2;
                if(f(x)*f(mid)<0){
                   xx=mid;
                }else{
                  x=mid;
                }
                printf("%.2f ",x);
            }
        }
    }
    return 0;
}