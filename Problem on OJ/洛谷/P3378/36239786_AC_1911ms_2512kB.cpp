#include <queue>
#include <iostream>
using namespace std;
priority_queue<int > a;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        if(temp==1){
            int sa;
            cin>>sa;
            a.push(-sa);
        }else if(temp==2){
            cout<<-a.top()<<endl;
        }else{
            a.pop();
        }
    }
    return 0;
}