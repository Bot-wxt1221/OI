#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n-1;i;i--){
        if(n%i==0){
            cout<<i;
            return 0;
        }
    }
}