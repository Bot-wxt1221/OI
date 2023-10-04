#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 
//顺序表存储结构
const int MAXSIZE = 80;  //预设的存储空间最大容量
typedef struct{
	int data[MAXSIZE];	//顺序存储空间
	int last;			//当前长度为last， last =-1为空表
} SeqList;
//顺序表初始化　
void init_SeqList(SeqList &L)
{ 
    L.last = -1;   	
}
//顺序表读入数据 
void input(SeqList &L)
{
	while(cin >> L.data[++L.last]);	
	L.last--;
}

//顺序表输出 
void print(const SeqList &L)
{
	for(int i = 0; i < L.last; i++)
		cout << L.data[i] << " ";
	cout << endl << L.last + 1;
}

int main()
{
	freopen("SeqList.in","r",stdin);
	freopen("SeqList.out","w",stdout);
	
	SeqList L;
	init_SeqList(L); 
	input(L);
	print(L);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
