#include <iostream>
#include <cstdio>
using namespace std;
char a[105],b[105],c[210];
int d[300];//统计每个字符出现的次数 
int D,r,u;//D 大写字数 r  小写字数   u  其他 
int main(){
	freopen("word10.out","w",stdout);
	freopen("word10.in","r",stdin);
	gets(a);gets(b);//a b  是原数据   c 是合并后的数组 
	int size=-1;
	for(int i=0;a[i]!='\0';i++){
		c[++size]=a[i]; //丢进去 下同 
		d[a[i]]++;//统计出现次数  下同 
	}
	c[++size]=' ';
	for(int i=0;b[i]!='\0';i++){
		c[++size]=b[i];
		d[b[i]]++;
	}
	c[++size]='\0';
	cout<<c<<endl;
	for(int i=0;c[i]!='\0';i++){//统计字符种数，分情况讨论 
		if('a'<=c[i]&&c[i]<='z'){//'a'---'z'的ASCLL是连续且有序的 
			r++;
		}else if('A'<=c[i]&&c[i]<='Z'){//'A'---'Z'的ASCLL是连续且有序的 
			D++;
		}else{
			u++;
		}
	}
	cout<<D<<' '<<r<<' '<<u<<endl;///不用解释 
	for(int i=0;i<26;i++){//按字母表顺序遍历 
		if(d[i+'a']){//先小写 
			printf("%c:%d\n",i+'a',d[i+'a']);
		}
		if(d[i+'A']){//再大写 
			printf("%c:%d\n",i+'A',d[i+'A']);
		}
	}
	return 0;
}
