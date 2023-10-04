#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
string b[10000005];//存字符串 
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i=1;//多少个字符 
	char temp2=' ';//读入数据 
	while(temp2!=EOF){//边界判定，是否读完 
		temp2=getchar();
		if(temp2==EOF){
				break;
			}
		while(('a'<=temp2&&temp2<='z')||('A'<=temp2&&temp2<='Z')){//getchar优化速度 
			b[i]=b[i]+temp2;//拼接 
			temp2=getchar();
			if(temp2==EOF){
				break;
			}
		}
		int temp=0;
		while(temp2==' '){//存空格  将字符串后的空格放到 字符串前面，翻转后就正常了 
			temp++;
			temp2=getchar();
			if(temp2==EOF){
				break;
			}
			b[i]=' '+b[i];
		}
		b[i+1]=temp2;
		i++;
	}
	for(int j=1;j<=(i-1)/2;j++){//交换 
		swap(b[j],b[i-j]);
	}
	for(int j=1;j<i;j++){//输出 
		cout<<b[j];
	}
	return 0;
}
