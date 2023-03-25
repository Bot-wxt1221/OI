#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	string str1,str2;
	char ans[100];
	for(int i=0;i<n;i++){
		ans[i]=min(str1[i],str2[i]);
	}
	ans[n]='\0';
	cout<<ans;
} 