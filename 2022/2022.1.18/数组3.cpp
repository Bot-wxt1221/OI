#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int main(){
	int a[3][4]={0};
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			a[i][j]=4*i+j+1;//2άת1ά 
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<setw(3)<<a[i][j];
		}
		cout<<endl;
	} 
	return 0;
}

