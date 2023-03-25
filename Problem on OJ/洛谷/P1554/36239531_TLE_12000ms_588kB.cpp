#include <iostream>
#include <sstream>
using namespace std;
int ans[10];
int main(){
    int n,m;
    cin>>n>>m;
    char a;
    for(int i=n;i<=m;i++){
        while(i){
            ans[i%10]++;
            i=i/10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<ans[i]<<' ';
    }
    
    return 0;
}