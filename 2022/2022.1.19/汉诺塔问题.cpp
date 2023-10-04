#include <iostream>
#include <cstdio>
using namespace std;
void move_h(int m,char x,char y,char z){
	if(m==1){
		cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl; 
	}else{
		move_h(m-1,x,z,y);
		cout<<"把一个盘子从"<<x<<"移动到"<<z<<endl;
		move_h(m-1,y,x,z);
	}
} 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	move_h(n,'A','B','C');
	return 0;
}

