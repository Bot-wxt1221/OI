#include <iostream>
using namespace std;
int main(){
    int m;
    string n;
    cin>>m>>n;
    int ans=0;
    for(int i=n.size()-1;i>=0;i--){
        if(n[i]!=0){
            if(ans==0){
                cout<<n[i]<<'*'<<m<<'^'<<i;
            }
            else{
                cout<<'+'<<n[i]<<'*'<<m<<'^'<<i;
            }
        }
        ans++;
    }
}