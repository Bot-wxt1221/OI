#include <iostream>
using namespace std;
bool h[10005];
int main(){
    int l,m,u,v;
    cin>>l>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        for(int j=u;j<=v;j++){
            h[j]=1;
        }
    }
    int num=0;
    for(int i=1;i<=l;i++){
        if(h[i]==0){
            num++;
        }
    }
    cout<<num+1;
}