#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char a[2005];
string o_string(int b){
   int n=0;
   while(b){
    a[n++]=b%10+'0';
    b=b/10;}
    a[n]='\0';
string abc=a;
return abc;
}
int main()
{
    int n;
    cin>>n;
    string temp;
    for(int i=n+1;1;i++){
        temp=o_string(i);
        bool ca=1;
        for(int j=0;j<temp.size();j++){
            if(temp[j]!=temp[temp.size()-1-j]){
                ca=0;
            }
        }
        if(ca){
            cout<<i;
            break;
        }
    }
    return 0;
}