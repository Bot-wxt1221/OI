#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class peo{
    public:
    string ren;
    int n;
};
bool cmp(peo a,peo b){
    return a.n>b.n;
}
peo a[30];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ren;
        a[i].n=i;
    }
    sort(a+1,a+n,cmp);
    cout<<a[1].n<<endl<<a[1].ren;
}