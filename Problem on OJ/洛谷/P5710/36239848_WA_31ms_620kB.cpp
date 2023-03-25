#include <iostream>
using namespace std;
int main(){
    int x;
    bool ans[2];
    cin>>x;
    ans[0]=(x+1)%2;
    ans[1]=x>4&&x<12;
    if(ans[0]&&ans[1]){
        cout<<1<<' ';
    }
    else {
        cout<<0<<' ';
    }
    if(ans[0]||ans[1]){
        cout<<1<<' ';
    }
    else {
        cout<<0<<' ';
    }
    if((ans[0] && !ans[1] || ans[1] && !ans[0])){
        cout<<1<<' ';
    }
    else {
        cout<<0<<' ';
    }
    if(!(ans[0]&&ans[1])){
        cout<<1<<' ';
    }
    else {
        cout<<0<<' ';
    }
}