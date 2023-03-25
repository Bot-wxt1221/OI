#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
int main()
{
	char a[1000]={0};
	int index=0;
	while(cin>>a){

		for(int i=0;a[i]!='\0';i++){
			if(a[i]=='z') a[i]='a';
			else if(a[i]=='Z') a[i]='A';
			else a[i]++;
	
		}	
		for(int i=0;a[i]!='\0';i++){
			cout << a[i];
		}
		cout << " ";			
	}
	
	
	return 0;
}

