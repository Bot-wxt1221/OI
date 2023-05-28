#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cstdlib>
const int  SIZE = 100; // ջ�ĳ�ʼ����
const int  ADDSIZE = 5; // ջ�ĵ�λ��������
using namespace std;// �����ռ�
const int INF = -0xfffffff;// ���ڿ�ջʱ��ֹ���Σ�����һ�����ܶ�ȡ�ĵ�ַ���ö�ȡ�������Σ�
template <class T>
struct Strack
{
	T *top;// ջ����ָ��
	T *base;// ջ�׵�ָ��
	int strackSize;//ջ����
	void init()//ջ�ĳ�ʼ��
	{
		base = (T *)malloc(SIZE * sizeof(T));//�����ڴ�
		top = base;
		strackSize = SIZE;
	}
 
	T Top()
	{// ����ջ��Ԫ��
		if (top == base)
			return INF;// �������ε�ַ
		return *(top - 1);
	}
 
	bool pop()
	{// ɾ��ջ��Ԫ��
		if (top == base)
			return false;
		top--;
		return true;
	}
 
	void push(T x)
	{//ջ������Ԫ��
		if (isPull()) {//����ڴ治�����·����ڴ�
			base = (T *)realloc(base, (strackSize + ADDSIZE)*(sizeof(T)));
			top = base + strackSize;
			strackSize += ADDSIZE;
		}
		*top++ = x;
	}
 
	bool isEmpty()
	{//�ж�ջ�Ƿ�Ϊ��
		if (top == base)
			return true;
		return false;
	}
 
	bool isPull()//��������
	{
		if (top - base == strackSize)// һ��pushһ�����Ե�top - base = strackSizeʱ��
			return true;
		else
			return false;
	}
};
 
int compareNumber(char x)//�����ȽϷ��ŵ����ȼ�
{
	if (x == '+' || x == '-')
		return 0;
	if (x == '*' || x == '/')
		return 1;
	return -1;
}
 
void change(char *mid, char *suxfix)//��׺���ʽת��Ϊ��׺���ʽ     
{
	int i = 0, len = strlen(mid), mid_index = 0;
	char c;
	Strack<char >intElements;// int���ݼ�
	intElements.init();
	intElements.push('#');// ���������������Ԫ��
	while (i < len)
	{
		if (mid[i] == '(')
		{
			intElements.push(mid[i]);
			i++;
		}
		else if (mid[i] == ')')
		{
			while (intElements.Top() != '(')
			{
				suxfix[mid_index++] = intElements.Top();
				suxfix[mid_index++] = ' ';
				intElements.pop();
			}
			intElements.pop();
			i++;
		}
		else if (mid[i] == '+' || mid[i] == '-' || mid[i] == '/' || mid[i] == '*')
		{
			while (compareNumber(intElements.Top()) >= compareNumber(mid[i]))
			{
				suxfix[mid_index++] = intElements.Top();
				suxfix[mid_index++] = ' ';
				intElements.pop();
			}
			intElements.push(mid[i]);
			i++;
		}
		else if (mid[i] >= '0'&&mid[i] <= '9')
		{
			while (mid[i] >= '0'&&mid[i] <= '9')
			{
				suxfix[mid_index++] = mid[i];
				i++;
			}
			suxfix[mid_index++] = ' ';
		}
		else
		{
 
		}
	}
	while (intElements.Top() != '#') {
		suxfix[mid_index++] = intElements.Top();
		suxfix[mid_index++] = ' ';
		intElements.pop();
	}
	suxfix[mid_index] = 0;
}
 
double countSuxfix(char *suxfix)//�����׺���ʽ   suxfix��׺���ʽ
{
	int len = strlen(suxfix);
	double x;
	Strack <int >intElements;
	intElements.init();
	int i = 0;
	while (i<len) {
		if (suxfix[i] == ' ')// ���ڱ��ʽ��Ч�ַ�����������ѭ��
		{
			i++;
			continue;
		}
		switch (suxfix[i])
		{
		case '+':
			x = intElements.Top();//����ԭ��ͼ��
			intElements.pop();
			x = intElements.Top() + x;
			intElements.pop(); i++;
			break;
		case '-':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top() - x;
			intElements.pop();
			i++;
			break;
		case '*':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top()*x;
			intElements.pop();
			i++;
			break;
		case '/':
			x = intElements.Top();
			intElements.pop();
			x = intElements.Top() / x;
			intElements.pop();
			i++;
			break;
		default:
		{
			x = 0;
			while (suxfix[i] >= '0'&&suxfix[i] <= '9') {
				x = x * 10 + suxfix[i] - '0';// ����2��������һ��*10���Դ�����
				i++;
			}
		}
		}
 
		intElements.push(x);
	}
	return intElements.Top();
}
int main()
{
	char str[1000];
	char newStr[1000];
	scanf("%s", str);
	change(str, newStr);
	cout << countSuxfix(newStr) << endl;
	return 0;
}
