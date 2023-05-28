#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen(".out","w",stdout); 
	char a[5]={'a','b','c','d','e'};//等同于char a[]="China"      '\0'是C/C++定义的标记字符数组末尾 
	for(int i=0;i<5;i++){
		cout<<a[i];
	}
	return 0;
}
/*str[]="china";
str="china";
str2=str1;
*/
//以上不合法 
