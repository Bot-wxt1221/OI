#include <iostream>
using namespace std;
int _max,_min;
int p[5005];
int z[5005];
void dfs(int n);
int main(){
    int l,n;
    cin>>l>>n;
    for(int i=1;i<=n;i++){
        cin>>z[i];
    }
    for(int i=1;i<=n;i++){
        _max=max(_max,max(l-p[i]+1,p[i]));
        _min=max(_min,min(l-p[i]+1,p[i]));
    }
    cout<<_max<<' '<<_min;
    return 0;
}