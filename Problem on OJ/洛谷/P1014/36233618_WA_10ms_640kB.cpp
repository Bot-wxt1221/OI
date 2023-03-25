#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp;
    for(temp=1;n>temp;temp++,n-=temp);
    temp+=n;
    temp--;
    cout<<n<<'/'<<temp;
}