#include <iostream>
using namespace std;
int main(){
    int x,n;
    long long a=0;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        x++;
        if(x>7){
            x=x-7;
        }
        if(x<=5){
            a+=250;
        }
    }
    cout<<long;
    return 0;
}