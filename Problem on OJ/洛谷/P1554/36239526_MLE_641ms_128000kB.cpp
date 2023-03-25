#include <iostream>
#include <sstream>
using namespace std;
int ans[10];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        stringstream *p=new stringstream;
        *p<<i;
        char a;
        while(*p>>a){
            ans[a-'0']++;
        }
        delete *p;
    }
    for(int i=0;i<10;i++){
        cout<<ans[i]<<' ';
    }
}