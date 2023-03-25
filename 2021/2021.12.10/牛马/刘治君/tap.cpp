//   n=2                       1             =>2^0        
//   n=3                    1     1          =>2^1
//   n=4                  1  1  1   1        =>2^2
//   ...                   .........
//   n=n                1 1 ........1 1      =>2^(n-2)
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std; 
int n;
long long int f=1;
int main(){
	freopen("tap.in","r",stdin);  
	freopen("tap.out","w",stdout);  
	cin>>n;
	if(n==1){
		cout<<0;
	}else{
		for(int i=1;i<=n-2;i++){
			f*=2;               //f=2^(n-2) 
		}
		cout<<f;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
