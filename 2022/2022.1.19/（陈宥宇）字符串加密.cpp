#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char a[200][205];
	int i=0;
	//输入 
	while(cin.getline(a[i],205)) i++;//输一行 
	//加密+输出 
	int k=0;
	for(int j=0;j<i;j++)//双重循环 
	{
		k=0;
		while(a[j][k]!='\0')
		{
			if(a[j][k]!=' ') printf("%c",a[j][k]+1);//加密 
			if(a[j][k]==' ') cout << ' ';//是空格打印空格 
			k++;
		}
		cout << endl;
	}
	return 0;
}
