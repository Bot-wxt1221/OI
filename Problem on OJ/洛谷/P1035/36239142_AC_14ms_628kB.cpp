#include <iostream>
using namespace std;
int main(){
    int k;
    cin>>k;
    long long n;
    double a=0;
    for(n=1;a<=k;n++){
        a=a+1.0/n;
    }
    cout<<n-1;
    return 0;
}