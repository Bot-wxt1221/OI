#include <iostream>
#include <cstring>
using namespace std;
bool cm[10];
int main(){
    for(int i=100;i<=999;i++){
        int j=i*2;
        int m=i*3;
        memset(cm,sizeof(cm),0);
        cm[i/100]=1;cm[(i%100-i%10)/10]=1;cm[i%10]=1;
        cm[j/100]=1;cm[(j%100-j%10)/10]=1;cm[j%10]=1;
        cm[m/100]=1;cm[(m%100-m%10)/10]=1;cm[m%10]=1;
        for(int i=0;i<=9;i++){
            if(!cm[i]){
                continue;
            }
        }
        cout<<i<<' '<<j<<' '<<m<<endl;
    }
    return 0;
}