#include <iostream>
#include <algorithm>
using namespace std;
string to_er(int x){
    string a;
    while(x){
        a+=char(x%2+'0');
        x/=2;
    }
    reverse(a.begin(),a.end());
    return a;
}
void dfs(int x){
    if(x==1){
        cout<<"2(0)";
        return ;
    }
    string a=to_er(x);
    for(int i=0;i<a.size();i++){
        cout<<"2(";
        if(a[1]=='1')
            dfs(a.size()-i-1);
        cout<<")+";
    }
}
int main(){
    int n;
    cin>>n;
    dfs(n);
    return 0;
}