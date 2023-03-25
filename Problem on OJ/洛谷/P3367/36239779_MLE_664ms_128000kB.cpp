#include <iostream>
using namespace std;
int f[10005];
int find(int x){
    if(x==f[x]){
        return x;
    }
    return f[x]=find(x);
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    int z,x,y;
    for(int i=1;i<=m;i++){
        cin>>z>>x>>y;
        if(z==1){
            f[find(y)]=x;
        }
        if(z==2){
            if(find(x)==find(y)){
                cout<<'Y'<<endl;
            }
            else{
                cout<<'N'<<endl;
            }
        }
    }
}