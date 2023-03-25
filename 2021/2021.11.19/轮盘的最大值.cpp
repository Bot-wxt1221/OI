#include <iostream>
#include <cstdio>
using namespace std;
int cnt=0;
int worka(int x);
int workb(int x);
int a[]={0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6,
27, 13, 36, 11, 30, 8, 23, 10, 5, 24,
16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7,
28, 12, 35, 3, 26};
int b[]={0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15, 3, 24, 36, 13, 1, 00, 27, 10,
25, 29, 12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	for(int i=2;i<=36;i++){
		int ia=worka(i);
		int ib=workb(i);
		cout<<max(ia,ib)<<endl;
		if(ia<ib){
		//	cout<<i<<' '<<ia<<' '<<ib<<endl;
			cnt++;
		}
	}
	cout<<cnt<<"¸ö";
	return 0;
}
int worka(int x){
	int _max=0;
	for(int i=0;i<36;i++){
		int temp=0;
		for(int j=i;j<=i+x-1;j++){
			temp+=a[j%36];
		}
		_max=max(_max,temp);
	}
	return _max;
}
int workb(int x){
	int _max=0;
	for(int i=1;i<37;i++){
		int temp=0;
		for(int j=i;j<=i+x-1;j++){
			temp+=b[j%37];
		}
		_max=max(_max,temp);
	}
	return _max;
}
