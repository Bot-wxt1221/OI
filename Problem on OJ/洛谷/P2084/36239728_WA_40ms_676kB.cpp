#include <iostream>
using namespace std;
int main(){
    int m;
    string n;
    cin>>m>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]!='0'){
            if(i==0){
                cout<<n[i]<<'*'<<m<<'^'<<i;
            }
            else{
                cout<<'+'<<n[i]<<'*'<<m<<'^'<<i;
            }
        }
    }
}