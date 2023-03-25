#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int u,l,d,s,o;
int i=0;
void tong(char a){
	if('a'<=a&&a<='z'){
		l++;
	}else if('A'<=a&&a<='Z'){
		u++;
	}else if('0'<=a&&a<='9'){
		d++;
	}else if(a==' '){
		s++;
	}else if(a!=EOF){
		o++;
	}
	return ;
}
int main(){
	freopen("article.in","r",stdin);
	freopen("article.out","w",stdout);
	int n=0;char a=getchar();
	tong(a);
	while(a!=EOF){
		while(a==' '||a=='\n'||a=='\r'){
			a=getchar();
			tong(a);
			if(a==EOF){
				break;
			}
		}
		if(a==EOF){
			break;
		}
		a=getchar();
		tong(a);
		if(a==EOF){
			n++;
			break;
		}
		while(a!=' '&&a!='\n'&&a!='\r'){
			a=getchar();
			if(a==EOF){
				break;
			}
			tong(a);
			
		}
		n++;
	}
	printf("uppercase:%d\nlowercase:%d\ndigit:%d\nspace:%d\nother:%d\nword:%d\n",u,l,d,s,o,n);
	return 0;
}

