#include <iostream>
using namespace std;
int a[1000005],b[1000005];
int main(){
    int n,m,s=0,temp1,temp2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>temp1>>temp2;
        for(int j=s;j<s+temp2;j++){
            a[j]=a[j-1]+temp1;
        }
        s+=temp2;
    }
    s=0;
    for(int i=1;i<=m;i++){
        cin>>temp1>>temp2;
        for(int j=s;j<s+temp2;j++){
            b[j]=b[j-1]+temp1;
        }
        s+=temp2;
    }
    int te=0;
    int zhuang=0;//0 齐头 1 KC 2 SH
    for(int i=0;i<s;i++){
        if(a[i]<b[i]){
            if(zhuang!=1){
                te++;
                zhuang=1;
            }
        }else if(a[i]>b[i]){
            if(zhuang!=2){
                te++;
                zhuang=2;
            }
        }else if(a[i]==b[i]){
            if(zhuang!=0){
                te++;
                zhuang=0;
            }
        }
    }
    cout<<te;
}