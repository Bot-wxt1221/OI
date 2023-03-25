#include <iostream>
using namespace std;
int main(){
    int l,r,num,temp;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        temp=i;
        while(temp){
            if(temp%10==2){
                num++;
            }
            temp=temp/10;
        }
    }
    cout<<num;
    return 0;
}