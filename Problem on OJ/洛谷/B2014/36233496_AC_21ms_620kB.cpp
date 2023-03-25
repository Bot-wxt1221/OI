#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    double r;
    const double PI=3.14159;
    cin>>r;
    printf("%.4lf %.4lf %.4lf",r*2,r*2*PI,r*r*PI);
    return 0;
}