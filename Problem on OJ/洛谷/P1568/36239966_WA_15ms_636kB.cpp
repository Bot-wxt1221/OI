#include <iostream>
using namespace std;
int a[10005],b[10005];
int main(){
    int n,m,s=0,temp1,temp2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>temp1>>temp2;
        for(int i=s;i<s+temp2;i++){
            a[i]=a[i-1]+temp1;
        }
        s+=temp2;
    }
    for(int i=1;i<=m;i++){
        cin>>temp1>>temp2;
        for(int i=s;i<s+temp2;i++){
            b[i]=b[i-1]+temp1;
        }
        s+=temp2;
    }
    s=s/2;
    int te=0;
    int zhuang=0;//0 齐头 1 KC 2 SH
    for(int i=1;i<=s;i++){
        if(a[i]<b[i]){
            if(zhuang!=1){
                te++;
                zhuang=1;
            }
        }else if(a[i]==b[i]){
            if(zhuang!=0){
                te++;
                zhuang=0;
                }
            }else if(zhuang!=2){
                te++;
                zhuang=2;
            }
    }
    cout<<te;
}