#include <iostream>
#include <cmath>
int a[40005];
using namespace std;
int main(){
    int temp,n,he=0,zhu=0;
    cin>>n;
    while(he!=n){
        cin>>temp;
        for(int i=1;i<=temp;i++){
            a[++he]=zhu;
        }
        if(zhu==0){
            zhu=1;
        }else{
            zhu=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i*n+j];
        }
        cout<<endl;
    }
}