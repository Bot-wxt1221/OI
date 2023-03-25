#include <iostream>
using namespace std;
int main(){
    int x,n;
    unsigned long long a=0;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        if(x<=5){
            a+=250;
        }
        x++;
        if(x==8){
            x=1;
        }
    }
    cout<<a;
    return 0;
}