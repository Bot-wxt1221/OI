#include <iostream>  
#include <string>
#include<cstdio>

using namespace std;

//���ǰ׺0���������ǿ��ַ�������Ϊ0 
inline void clear(string& a)
{
    while(a.length()>0 && a[0]=='0')
        a.erase(0, 1);
    if(a == "")
        a = "0";
}

//���a>=b�򷵻��棨�������ǰ׺��ᱻ������ 
bool isBigger(string a, string b)
{
    clear(a);
    clear(b);
    if(a.length() > b.length())
        return true;
    if(a.length()==b.length() && a>=b)
        return true;
    return false; 
}


//�����߾����������ӷ� a+b 
string stringAddString(string a, string b)
{
    //1����λ��������������ֱ���������ͬ���� 
    while(a.length() < b.length())         
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b; 
    //2�����㣬�ڿ�ͷ�ټ�һ��0�Ա��λ
    a = '0' + a;
    b = '0' + b;
    //3���ӵ�λ��ʼ��ӣ�ע���λ
    for(int i=a.length()-1; i>=0; i--)
	{
        a[i] = a[i] + b[i] - '0';
        if(a[i] > '9')
		{
            a[i] = a[i] - 10;
            a[i-1] += 1;
        }
    } 
    clear(a);
    return a;  
}

//�����߾������������� a-b 
string stringSubString(string a, string b)
{
    bool aBigger = true;
    //1����λ��������������ֱ���������ͬ���� 
    while(a.length() < b.length())         
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b;  
    //2���Ʋ�������ֵ������Ϊǰ���С 
    if(a < b)  
    {  
        aBigger = false;  
        string buf = b;  
        b = a;  
        a = buf;  
    } 
    //3���ӵ�λ��ʼ�����ע���λ
    for(int i=a.length()-1; i>=0; i--)
	{
        if(a[i] >= b[i])
		{
            a[i] = a[i] - (b[i] - '0');
        }
		else
		{
            a[i] = a[i] + 10;
            a[i-1] -= 1;
            a[i] = a[i] - (b[i] - '0');
        }
    }
    clear(a);
    if(!aBigger)   
        a = '-' + a;
    return a;    
}

//�����߾����������˷� a*b
//�����ӷ� 
string stringMultString(string a, string b)
{
    string result = "0";
    if(a.length() < b.length())
	{
        string buf = a;
        a = b;
        b = buf;
    } 
    //��λ����һλ������ֱ��ʹ�üӷ�
    //��λ����������d*10^n��������ת��Ϊ��λ������һλ�� 
    //��λ�����Զ�λ������ת��Ϊ���ɸ���λ������һλ�����
    for(int i=b.length()-1; i>=0; i--)
	{
        for(int j=0; j<b[i]-'0'; j++)
		{
            result = stringAddString(result, a);
        }
        a = a + '0';
    }
    clear(result);
    return result; 
}

//�����߾������������� a/b 
//�������� 
string stringDivString(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "��";
        
    string result = "";
    string remainder = "";
    //�Ӹ�λ��ʼ�������������һ�� 
    // һ��ȡλ�պô��ڱ�������ʼ�ü������� 
    for(int i=0; i<a.length(); i++)
	{
        remainder = remainder + a[i];
        result = result + '0';
        while(isBigger(remainder, b))
		{
            result[result.length()-1]++;
            remainder = stringSubString(remainder, b);
        }
    }
    clear(result);
    return result;
}

//�����߾������������� a%b
//�������� 
string stringModString(string a, string b)
{
    clear(a);
    clear(b);
    if(b == "0")
        return "��";   
           
    string result = "";
    string remainder = "";
    //�ͳ���Ψһ��������Ƿ���ֵ��һ�� 
    for(int i=0; i<a.length(); i++)
	{
        remainder = remainder + a[i];
        result = result + '0';
        while(isBigger(remainder, b))
		{
            result[result.length()-1]++;
            remainder = stringSubString(remainder, b);
        }
    }
    clear(remainder);
    return remainder;
} 
      
//�����߾����������Լ�� gcd(a,b)
//�������� 
string stringGcd(string a, string b)
{
    clear(a);
    clear(b);
    if(!isBigger(a, b))
	{
        string buf = a;
        a = b;
        b = buf;
    }
    //ʹ��շת����������Լ��
    if(b == "0")
	{
        return a;
    }
	else
	{
        return stringGcd(b, stringModString(a, b)); 
    }
}
 
//�����߾���������С������ lcm(a,b)
//�����˷�
//��������
//�������Լ�� 
string stringLcm(string a, string b)
{
    clear(a);
    clear(b);
    string buf = stringMultString(a, b);
    //ʹ�ù�ʽ lcm(a,b)=a*b/gcd(a,b) 
    if(buf == "0")
	{
        return "0";
    }
	else
	{
        return stringDivString(buf, stringGcd(a, b)); 
    }
}

int main()
{
    string a, b;
    
    freopen("cirno1.in","r",stdin);
    freopen("cirno1.out","w",stdout);   
    
    cin >> a >> b;
    cout << stringAddString (a, b) << endl ;
    cout << stringSubString (a, b) << endl ;
	cout << stringMultString(a, b) << endl ;
    cout << stringDivString (a, b) << endl ;
    cout << stringModString (a, b) << endl ; 
	//cout << stringGcd (a,b) <<endl ;
	//cout << stringLcm (a,b) <<endl ;
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
