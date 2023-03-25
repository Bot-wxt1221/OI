#include <iostream>
using namespace std;
int f[10005];
int find(int x){
    if(x=f[x]){
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
    for(int i=1;i<=m;i++){
        int z,x,y;
        cin>>z>>x>>y;
        if(z==1){
            f[find(x)]=find(y);
        }
        if(z==2){
            if(find(x)==find(y)){
                cout<<'y'<<endl;
            }
            else{
                cout<<'N'<<endl;
            }
        }
    }
}