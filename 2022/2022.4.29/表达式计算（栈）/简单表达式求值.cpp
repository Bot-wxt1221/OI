#include <iostream>
#include <stack>
#include <string>
using namespace std;

string exp;				//存放中缀表达式
string postexp;			//存放后缀表达式
string getpostexp();	//返回postexp 
void Trans();      		//将exp转换成postexp
double GetValue();		//计算后缀表达式postexp的值


int main(){  
	string str = "(56-20)/(4+2)";
   	exp = str;
   	cout << "中缀表达式: " << str << endl;
	cout << "中缀转换为后缀" << endl;
	Trans();
	cout << "后缀表达式: " << getpostexp() << endl;
	cout << "求后缀表达式值" << endl;
	cout << "求值结果:   " << GetValue() << endl;
	return 0;
}

string getpostexp(){	//返回postexp 
	return postexp;
}

void Trans(){			//将算术表达式exp转换成后缀表达式postexp
	stack<char> opor;		//定义运算符栈opor
	int i = 0;			//i为exp的下标
	char ch, e;
	while (i < exp.length()){	//exp表达式未扫描完时循环
		ch = exp[i];
		if (ch == '(')		//遇到左括号
			opor.push(ch);		//将左括号直接进栈
		else if (ch == ')'){		//遇到右括号
			while (!opor.empty() && opor.top() != '('){
				e = opor.top();	//将栈中'('之前的运算符退栈并存入postexp
				opor.pop();
				postexp += e;
			}
			opor.pop();		//将(退栈
		}
		else if (ch == '+' || ch == '-'){		//遇到加或减号
			while (!opor.empty() && opor.top() != '('){
				e = opor.top();			//将栈中(之前的所有运算符退栈
				opor.pop();			//并存入postexp
				postexp += e;
			}
			opor.push(ch);			//再将'+'或'-'进栈
		}
		else if (ch == '*' || ch == '/'){		//遇到'*'或'/'号
			while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/')){
				e = opor.top();			//将栈中(之前的所有*或/依次出栈
				opor.pop();			//并存入postexp
				postexp += e;
			}
			opor.push(ch);			//再将'*'或'/'进栈
		}
		else{				   //遇到数字字符
			string d = "";
			while (ch >= '0' && ch <= '9'){  //遇到数字
				d += ch;			   //提取所有连续的数字字符
				i++;
				if (i < exp.length())	   //exp没有遍历完时取下一个字符ch
		 			ch = exp[i];
				else			   //exp遍历完毕时退出数字判断
		 			break;
			}
			i--;			   //退一个字符
			postexp += d;		   //将数字串存入postexp
			postexp += "#";		   //用#标识一个数字串结束
		}
		i++;				   //继续处理其他字符
	}
	while (!opor.empty()){	//此时exp扫描完毕,栈不空时循环
		e = opor.top();
		opor.pop();		//将栈中所有运算符退栈并放入postexp
		postexp += e;
	}
}

double GetValue(){			//计算后缀表达式postexp的值
	stack<double> opand;			//定义运算数栈opand
	double a, b, c, d;
	char ch;
	int i = 0;
	while (i < postexp.length()){		//postexp字符串未扫描完时循环
		ch = postexp[i];
		switch (ch){
			case '+':				//遇到+
				a = opand.top(); opand.pop();	//退栈运算数a
				b = opand.top(); opand.pop();	//退栈运算数b 
				c = b + a;				//计算c
				opand.push(c);			//将计算结果进栈
				break;
			case '-':				//遇到-
				a = opand.top(); opand.pop();		//退栈运算数a
				b = opand.top(); opand.pop();		//退栈运算数b 
				c = b - a;				//计算c
				opand.push(c);			//将计算结果进栈
				break;
			case '*':				//遇到*
				a = opand.top(); opand.pop();		//退栈运算数a
				b = opand.top(); opand.pop();		//退栈运算数b 
				c = b * a;				//计算c
				opand.push(c);			//将计算结果进栈
				break;
			case '/':				//遇到/
				a = opand.top(); opand.pop();		//退栈运算数a
				b = opand.top(); opand.pop();		//退栈运算数b 
				c = b / a;				//计算c
				opand.push(c);			//将计算结果进栈
				break;
			default:			//遇到数字字符
				d = 0;			//将连续的数字符转换成数值存放到d中
				while (ch >= '0' && ch <= '9'){
					d = 10 * d + (ch - '0');
					i++;
					ch = postexp[i];
				}
				opand.push(d);		//将数值d进栈
				break;
		}
		i++;			//继续处理其他字符
	}
	return opand.top();		//栈顶元素即为求值结果
}




