#include <iostream>
using namespace std;
char a[30]={"0123456789ABCDEFGHIJKLMN"};
void dfs(int n,int m);
int main(){
    int n,m;
    cin>>n>>m;
    cout<<n<<'=';
    dfs(n,m);
    cout<<"(base"<<m<<")";
    return 0;
}
void dfs(int n,int m){
    if(n==0){
        return;
    }
    int temp=n%m;
    if(temp<0){
        temp-=m;
        temp--;
    }
    dfs(n/m,m);
    cout<<a[temp];
}