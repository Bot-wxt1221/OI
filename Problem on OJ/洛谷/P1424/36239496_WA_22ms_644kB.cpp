#include <iostream>
using namespace std;
int main(){
    int x,n;
    unsigned long long a=0;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        x++;
        if(x==7){
            x=1;
        }
        
        if(x<=5){
            a+=250;
        }
    }
    cout<<a;
    return 0;
}