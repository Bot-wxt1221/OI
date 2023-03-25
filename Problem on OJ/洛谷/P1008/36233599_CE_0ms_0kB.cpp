#include <iostream>
#include <cstring>
using namespace std;
bool cmp[10];
int main(){
    for(int i=100;i<=999;i++){
            int j=i*2;
            int m=i*3;
            memset(cmp,sizeof(cmp),0);
            cmp[i/100]=1;cmp[(i%100-i%10)/10]=1;cmp[i%10]=1;
            cmp[j/100]=1;cmp[(j%100-j%10)/10]=1;cmp[j%10]=1;
            cmp[m/100]=1;cmp[(m%100-m%10)/10]=1;cmp[m%10]=1;
            for(int i=0;i<=9;i++){
                if(!cmp[i]){
                    continue;
                }
            }
            cout<<i<<' '<<j<<' '<<m<<endl;
        }
    }
    return 0;
}