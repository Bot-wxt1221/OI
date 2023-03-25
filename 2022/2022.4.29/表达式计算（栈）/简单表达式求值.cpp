#include <iostream>
#include <stack>
#include <string>
using namespace std;

string exp;				//�����׺���ʽ
string postexp;			//��ź�׺���ʽ
string getpostexp();	//����postexp 
void Trans();      		//��expת����postexp
double GetValue();		//�����׺���ʽpostexp��ֵ


int main(){  
	string str = "(56-20)/(4+2)";
   	exp = str;
   	cout << "��׺���ʽ: " << str << endl;
	cout << "��׺ת��Ϊ��׺" << endl;
	Trans();
	cout << "��׺���ʽ: " << getpostexp() << endl;
	cout << "���׺���ʽֵ" << endl;
	cout << "��ֵ���:   " << GetValue() << endl;
	return 0;
}

string getpostexp(){	//����postexp 
	return postexp;
}

void Trans(){			//���������ʽexpת���ɺ�׺���ʽpostexp
	stack<char> opor;		//���������ջopor
	int i = 0;			//iΪexp���±�
	char ch, e;
	while (i < exp.length()){	//exp���ʽδɨ����ʱѭ��
		ch = exp[i];
		if (ch == '(')		//����������
			opor.push(ch);		//��������ֱ�ӽ�ջ
		else if (ch == ')'){		//����������
			while (!opor.empty() && opor.top() != '('){
				e = opor.top();	//��ջ��'('֮ǰ���������ջ������postexp
				opor.pop();
				postexp += e;
			}
			opor.pop();		//��(��ջ
		}
		else if (ch == '+' || ch == '-'){		//�����ӻ����
			while (!opor.empty() && opor.top() != '('){
				e = opor.top();			//��ջ��(֮ǰ�������������ջ
				opor.pop();			//������postexp
				postexp += e;
			}
			opor.push(ch);			//�ٽ�'+'��'-'��ջ
		}
		else if (ch == '*' || ch == '/'){		//����'*'��'/'��
			while (!opor.empty() && opor.top() != '(' && (opor.top() == '*' || opor.top() == '/')){
				e = opor.top();			//��ջ��(֮ǰ������*��/���γ�ջ
				opor.pop();			//������postexp
				postexp += e;
			}
			opor.push(ch);			//�ٽ�'*'��'/'��ջ
		}
		else{				   //���������ַ�
			string d = "";
			while (ch >= '0' && ch <= '9'){  //��������
				d += ch;			   //��ȡ���������������ַ�
				i++;
				if (i < exp.length())	   //expû�б�����ʱȡ��һ���ַ�ch
		 			ch = exp[i];
				else			   //exp�������ʱ�˳������ж�
		 			break;
			}
			i--;			   //��һ���ַ�
			postexp += d;		   //�����ִ�����postexp
			postexp += "#";		   //��#��ʶһ�����ִ�����
		}
		i++;				   //�������������ַ�
	}
	while (!opor.empty()){	//��ʱexpɨ�����,ջ����ʱѭ��
		e = opor.top();
		opor.pop();		//��ջ�������������ջ������postexp
		postexp += e;
	}
}

double GetValue(){			//�����׺���ʽpostexp��ֵ
	stack<double> opand;			//����������ջopand
	double a, b, c, d;
	char ch;
	int i = 0;
	while (i < postexp.length()){		//postexp�ַ���δɨ����ʱѭ��
		ch = postexp[i];
		switch (ch){
			case '+':				//����+
				a = opand.top(); opand.pop();	//��ջ������a
				b = opand.top(); opand.pop();	//��ջ������b 
				c = b + a;				//����c
				opand.push(c);			//����������ջ
				break;
			case '-':				//����-
				a = opand.top(); opand.pop();		//��ջ������a
				b = opand.top(); opand.pop();		//��ջ������b 
				c = b - a;				//����c
				opand.push(c);			//����������ջ
				break;
			case '*':				//����*
				a = opand.top(); opand.pop();		//��ջ������a
				b = opand.top(); opand.pop();		//��ջ������b 
				c = b * a;				//����c
				opand.push(c);			//����������ջ
				break;
			case '/':				//����/
				a = opand.top(); opand.pop();		//��ջ������a
				b = opand.top(); opand.pop();		//��ջ������b 
				c = b / a;				//����c
				opand.push(c);			//����������ջ
				break;
			default:			//���������ַ�
				d = 0;			//�����������ַ�ת������ֵ��ŵ�d��
				while (ch >= '0' && ch <= '9'){
					d = 10 * d + (ch - '0');
					i++;
					ch = postexp[i];
				}
				opand.push(d);		//����ֵd��ջ
				break;
		}
		i++;			//�������������ַ�
	}
	return opand.top();		//ջ��Ԫ�ؼ�Ϊ��ֵ���
}




