#include <iostream>
using namespace std;
int c[10005][10005];
int main(){
    int n,a,b,g,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b>>g>>k;
        for(int i=a;i<=a+g;i++){
            for(int j=b;j<=b+k;j++){
                c[i][j]++;
            }
        }
    }
    cin>>a>>b;
    if(c[a][b])
        cout<<c[a][b];
    else
        cout<<-1;
    return 0;
}