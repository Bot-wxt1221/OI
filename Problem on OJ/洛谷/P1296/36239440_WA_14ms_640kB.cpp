#include<iostream>
using namespace std;
int c[1000];
int main(){
    int a,b,d=0,e;
    cin>>a>>b;
    for(int i=1;i<=a;i++)
        cin>>c[i];
    for(int i=1;i<a;i++)
        for(int j=i+1;j<=a;j++){
            e=c[i]+b;
            if(e>=c[j])
                d++;
        }
    cout<<d;
    return 0;
}