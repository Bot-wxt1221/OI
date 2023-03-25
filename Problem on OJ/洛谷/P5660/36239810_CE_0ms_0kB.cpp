#include <cstdio>
using namespace std;
int main(){
    int ans=0;
    for(int i=1;i<=8;i++){
        if(getchar()=='1'){
            ans++;
        }
    }
    cout<<ans;
}