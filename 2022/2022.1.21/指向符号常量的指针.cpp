#include <iostream>
using namespace std;
void stringcpy(char *a,const char *b);
int main(){
	char a[20] = "Hello";
	char b[20];
	stringcpy(a ,b);
	cout <<a << endl << b; 
	return 0;
}
void stringcpy(char *a,const char *b){
	int i;
	for(i = 0;b[i] != '\0';i++){
		a[i] = b[i];
	}
	a[i] = '\0';
	return ;
}

