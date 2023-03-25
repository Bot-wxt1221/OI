#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
char a[100000];
int main(){
    cin>>a;
    reverse(a,a+strlen(a));
    cout<<a;
}