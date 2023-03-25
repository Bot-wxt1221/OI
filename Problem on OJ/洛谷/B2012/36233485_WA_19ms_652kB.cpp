#include <iostream>
using namespace std;
int main(){
    double a,b,c;
    cin>>a>>b;
    c=b/a;
    c=c/100;
    printf("%.3lf%%",c);
}