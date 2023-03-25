#include <iostream>
using namespace std;
int main(){
    int n,k,nonu;
    cin>>n>>k;
    int sum=n;
    nonu=sum;
    while(nonu-k>=0) 
    {
        nonu=nonu-k;
        sum++;
        nonu++;
    }
    cout<<sum;
    return 0;
}