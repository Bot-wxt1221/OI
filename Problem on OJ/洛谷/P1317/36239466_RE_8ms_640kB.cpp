#include <iostream>
#include <vector>
using namespace std;
vector<int>a;
int main(){
    int n,temp,num=0;
    cin>>n;
    a.clear();
    for(int i=1;i<=n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    temp=10000;
    for(int i=0;i<n;i++){
        if(temp==a[i]){
             a.erase(a.begin()+i);
        }
            temp=a[i];
    }
    for(int i=1;i<a.size()-1;i++){
        if(a[i-1]>a[i]&&a[i]<a[i+1]){
            num++;
        }
    }
    cout<<num;
}