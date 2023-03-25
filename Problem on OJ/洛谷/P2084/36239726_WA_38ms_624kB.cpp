#include <iostream>
using namespace std;
int main(){
    int m;
    string n;
    cin>>m>>n;
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]!='0'){
            if(i==n.size()-1){
                cout<<n[i]<<'*'<<m<<'^'<<i;
            }
            else{
                cout<<'+'<<n[i]<<'*'<<m<<'^'<<i;
            }
        }
    }
}