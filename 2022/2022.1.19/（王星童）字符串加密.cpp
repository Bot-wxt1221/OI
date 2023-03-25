#include <iostream>
#include <cstdio>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char c;
	while(!cin.eof()){
		c=cin.get();
		if(c!=' '&&c!='\n'&&c!='\r'){//是否需要变换 
			if(c=='z'){//特判 
				cout<<'a';
			}else if(c=='Z'){//特判 
				cout<<'A';
			}else{//ASCLL码自加，符合题意 
				cout<<char(c+1);
			}
		}else{
			cout<<c;//不变换直接输出 
		}
	}
	return 0;
}

