#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cstdlib>
const int  SIZE = 100; // 栈的初始容量
const int  ADDSIZE = 5; // 栈的单位增加容量
using namespace std;// 命名空间
const int INF = -0xfffffff;// 用于空栈时防止尴尬，返回一个不能读取的地址，让读取的人尴尬；
template <class T>
struct Strack
{
	T *top;// 栈顶的指针
	T *base;// 栈底的指针
	int strackSize;//栈容量
	void init()//栈的初始化
	{
		base = (T *)malloc(SIZE * sizeof(T));//分配内存
		top = base;
		strackSize = SIZE;
	}
 
	T Top()
	{// 返回栈顶元素
		if (top == base)
			return INF;// 返回尴尬地址
		return *(top - 1);
	}
 
	bool pop()
	{// 删除栈顶元素
		if (top == base)
			return false;
		top--;
		return true;
	}
 
	void push(T x)
	{//栈顶插入元素
		if (isPull()) {//如果内存不够重新分配内存
			base = (T *)realloc(base, (strackSize + ADDSIZE)*(sizeof(T)));
			top = base + strackSize;
			strackSize += ADDSIZE;
		}
		*top++ = x;
	}
 
	bool isEmpty()
	{//判断栈是否为空
		if (top == base)
			return true;
		return false;
	}
 
	bool isPull()//判满函数
	{
		if (top - base == strackSize)// 一次push一个所以当top - base = strackSize时满
			return true;
		else
			return false;
	}
};
 
int compareNumber(char x)//用来比较符号的优先级
{
	if (x == '+' || x == '-')
		return 0;
	if (x == '*' || x == '/')
		return 1;
	return -1;
}
 
void change(char *mid, char *suxfix)//中缀表达式转换为后缀表达式     
{
	int i = 0, len = strlen(mid), mid_index = 0;
	char c;
	Strack<char >intElements;// int数据集
	intElements.init();
	intElements.push('#');// 特殊符号用来区分元素
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
 
double countSuxfix(char *suxfix)//计算后缀表达式   suxfix后缀表达式
{
	int len = strlen(suxfix);
	double x;
	Strack <int >intElements;
	intElements.init();
	int i = 0;
	while (i<len) {
		if (suxfix[i] == ' ')// 用于表达式有效字符集用完跳出循环
		{
			i++;
			continue;
		}
		switch (suxfix[i])
		{
		case '+':
			x = intElements.Top();//根据原理图看
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
				x = x * 10 + suxfix[i] - '0';// 连续2个数，第一个*10，以此类推
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
