#include <iostream>
#include <cstdio>
using namespace std;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	char c;
	while(!cin.eof()){
		c=cin.get();
		if(c!=' '&&c!='\n'&&c!='\r'){//�Ƿ���Ҫ�任 
			if(c=='z'){//���� 
				cout<<'a';
			}else if(c=='Z'){//���� 
				cout<<'A';
			}else{//ASCLL���Լӣ��������� 
				cout<<char(c+1);
			}
		}else{
			cout<<c;//���任ֱ����� 
		}
	}
	return 0;
}

