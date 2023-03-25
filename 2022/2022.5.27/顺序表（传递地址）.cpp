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
SeqList *init_SeqList()
{ 
    SeqList *L;	
	L = new SeqList; //L = (SeqList *)malloc(sizeof(SeqList));
    L->last = 0;
	L->data[0]=1;      
    return L;    
}
//顺序表读入数据 
void input(SeqList *L)
{
	L->last++;
	while(cin >> L->data[L->last])
		 L->last++;
	L->last--;
}

//顺序表输出 
void print(SeqList *L)
{
	for(int i = 0; i < L->last; i++)
		cout << L->data[i] << " ";	
	cout << endl << L->last + 1;
}

int main()
{
	freopen("SeqList.in","r",stdin);
	freopen("SeqList.out","w",stdout);
	
	SeqList *L;
	L = init_SeqList(); 
	input(L);
	print(L);
	delete L;  //free(L);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
