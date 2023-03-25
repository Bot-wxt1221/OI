#include <string>
#include <iostream>
using namespace std;
int main(){
    string abc,cba;
    cin>>abc;
    for(int i=0;i<abc.size();i++){
        cba[abc.size()-1-i]=abc[i];
    }
    cout<<cba;
}