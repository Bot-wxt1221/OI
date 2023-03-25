#include <iostream>
using namespace std;
int n,m;
long long dfs(int n1,int m1);
int main(){
    cin>>n>>m;
    cout<<dfs(1,1);
}
long long dfs(int n1,int m1){
    if(n1==1&&m1!=1){
        return 1;
    }
    if(m1==m){
        return 0;
    }
    return dfs(n1-1,m1+1)+dfs(n1+1,m1+1);
}