#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
bool is_pr(int n);
void work(int n);
int main(){
    int n;
    cin>>n;
    for(int i=4;i<=n;i+=2){
        work(i);
    }
    return 0;
}
void work(int n){
    while(n){
        for(int i=2;1;i++){
            if(is_pr(i)&&is_pr(n-i)){
                printf("%d=%d+%d\n",n,i,n-i);
                return;
            }
        }
    }
}
bool is_pr(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}