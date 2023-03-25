#include <iostream>
using namespace std;
int main(){
    int l,r,num;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        int temp=i;
        while(temp){
            if(temp%10==2){
                num++;
            }
            temp=temp/10;
        }
    }
    cout<<temp;
    return 0;
}