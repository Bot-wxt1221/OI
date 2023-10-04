#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
	freopen("bit6.in","w",stdout);
	srand(time(NULL));
	for(int i=1;i<=1000;i++){
		int ans=0;
		for(int j=1;j<=10;j++){
			ans+=rand();
		}
		if(rand()%2==0){
			cout<<"-";
		}
		cout<<ans<<endl;
	}
	return 0;
}
