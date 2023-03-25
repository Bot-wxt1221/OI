#include <iostream>
using namespace std;
int main(){
    int m;
    string n;
    cin>>m>>n;
    for(int i=0;i<n.size();i++){
        if(n[i]!='0'){
            if(i==n.size()-1){
                cout<<n[i]<<'*'<<m<<'^'<<n.size()-i;
            }
            else{
                cout<<n[i]<<'*'<<m<<'^'<<n.size()-i<<'+';
            }
        }
    }
    return 0;
}