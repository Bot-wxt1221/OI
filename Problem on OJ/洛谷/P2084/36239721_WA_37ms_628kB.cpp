#include <iostream>
using namespace std;
int main(){
    int m;
    string n;
    cin>>m>>n;
    for(int i=1;i<n.size();i++){
        if(n[i]!='0'){
            if(i==n.size()){
                cout<<n[i]<<'*'<<m<<'^'<<i;
            }
            else{
                cout<<n[i]<<'*'<<m<<'^'<<i<<'+';
            }
        }
    }
}