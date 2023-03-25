#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int main(){
	int a[][4]={{1},{0,6},{0,0,11}};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<endl;
	} 
	return 0;
}

