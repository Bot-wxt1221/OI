#include <iostream>
using namespace std;
int n,m;
long long dfs(int n,int m);
int main(){
    cin>>n>>m;
    cout<<dfs(1,1);
}
long long dfs(int n,int m){
    if(n==1&&m!=1){
        return 1;
    }
    if(m==::m){
        return 0;
    }
    return dfs(n-1,m)+dfs(n+1,m);
}