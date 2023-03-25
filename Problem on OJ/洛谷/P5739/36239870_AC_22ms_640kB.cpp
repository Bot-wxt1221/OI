#include <iostream>
using namespace std;
int dfs(int n);
int main(){
    int n;
    cin>>n;
    cout<<dfs(n);
    return 0;
}
int dfs(int n){
    if(n==1){
    return 1;
    }
    return n*dfs(n-1);
}