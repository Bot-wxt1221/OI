#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int main(){
	int a[][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<endl;
	} 
	return 0;
}

