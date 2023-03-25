#include <iostream>
using namespace std;
long long ans[105];
int main(){
    int ge=0;
    for(int i=0;cin>>ans[i]&&ans[i]!=0;i++){
        ge++;
    }
    for(int i=0;i<ge;i++){
        cout<<ans[i]<<' ';
    }
}