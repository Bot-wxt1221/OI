#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 
//˳���洢�ṹ
const int MAXSIZE = 80;  //Ԥ��Ĵ洢�ռ��������
typedef struct{
	int data[MAXSIZE];	//˳��洢�ռ�
	int last;			//��ǰ����Ϊlast�� last =-1Ϊ�ձ�
} SeqList;
//˳����ʼ����
void init_SeqList(SeqList &L)
{ 
    L.last = -1;   	
}
//˳���������� 
void input(SeqList &L)
{
	while(cin >> L.data[++L.last]);	
	L.last--;
}

//˳������ 
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
