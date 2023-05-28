#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int a[100005];
int main(){
//	freopen(".in","r",stdin);
	freopen("number3.in","w",stdout);
	int n,m;
	srand(time(NULL));
	n=rand()%1000;m=rand();
	cout<<n<<' '<<m<<endl;
	for(int i=1;i<=n/2;i++){
		a[i]=rand();
		cout<<a[i]<<' ';
	}
	for(int i=n/2+1;i<=n;i++){
		if(rand()%4==1){
			cout<<m-a[rand()%n]<<' ';
		}else{
			a[i]=rand();
			cout<<a[i]<<' ';
		}
	}
	return 0;
}

