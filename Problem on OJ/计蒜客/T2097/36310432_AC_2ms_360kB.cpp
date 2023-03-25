#include <iostream>
#include <cstdio>
#define Maxs 105
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
bool have[1005];
int queue[Maxs];
int size=0;
int r=0,l=0;
int main(){
	int m,n;
	m=read();
	n=read();
	int find=0;
	for(int i=1;i<=n;i++){
		int temp=read();
		if(have[temp]){//有缓存 
			continue;
		}else if(size==m){//没缓存而且内存已满 
			have[queue[r]]=0;
			r++;
			r=r%Maxs;
			queue[l]=temp;
			l=(l+1)%Maxs; 
			have[temp]=1;
		}else{//没缓存但内存没满 
			size++;
			queue[l]=temp;
			l=(l+1)%Maxs; 
			have[temp]=1;
		}
		find++;
	}
	cout<<find;
	return 0;
}
/*
Anything about this program:
Type:
	评测 
Description:
	这个翻译软件的原理很简单，它只是从头到尾，依次将每个英文单词用对应的中文含义来替换。对
于每个英文单词，软件会先在内存中查找这个单词的中文含义，如果内存中有，软件就会用它进行
翻译；如果内存中没有，软件就会在外存中的词典内查找，查出单词的中文含义然后翻译，并将这
个单词和译义放入内存，以备后续的查找和翻译。
假设内存中有 个单元，每单元能存放一个单词和译义。每当软件将一个新单词存入内存前，如果
当前内存中已存入的单词数不超过 ，软件会将新单词存入一个未使用的内存单元；若内存中
已存入 个单词，软件会清空最早进入内存的那个单词，腾出单元来，存放新单词。
假设一篇英语文章的长度为 个单词。给定这篇待译文章，翻译软件需要去外存查找多少次词典？
假设在翻译开始前，内存中没有任何单词。
Example:
	1:
		In:
		3 7
		1 2 1 5 4 4 1
		Out:
		5
More:
	手写循环队列 
*/

