#include <iostream>
#include <string>
using namespace std;
int main(){
    int a=1,b=1;
    string tem,temp;
    cin>>tem>>temp;
    for(int i=0;i<tem.size();i++){
        a=a*(tem[i]-'A'+1);
    }
    a=a%47;
    for(int i=0;i<temp.size();i++){
        b=b*(temp[i]-'A'+1);
    }
    b=b%47;
    if(a==b){
        cout<<"GO";
    }else{
        cout<<"STAY";
    }
    return 0;
}