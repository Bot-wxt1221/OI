#include <iostream>
using namespace std;
int main(){
	int x,y,ans=0,ans_m[10000]={0};
	cin>>x>>y;
	for(int i=x;i<=y;i++){
        if(i%400==0||i%4==0&&i%100){
            ans++;
            ans_m[ans]=i;
        }
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++){
		cout<<ans_m[i]<<' ';
	}
}