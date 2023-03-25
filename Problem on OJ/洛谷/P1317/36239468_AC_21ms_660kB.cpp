#include <iostream>
#include <vector>
using namespace std;
vector<int>a;
vector<int>b;
int main(){
    int n,temp,num=0;
    cin>>n;
    a.clear();
    b.clear();
    for(int i=1;i<=n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    temp=10000;
    for(int i=0;i<n;i++){
        if(temp!=a[i]){
             temp=a[i];
             b.push_back(a[i]);
    }
    }
    for(int i=1;i<(b.size()-1);i++){
        if(b[i-1]>b[i]&&b[i]<b[i+1]){
            num++;
        }
    }
    cout<<num;
}