#include <cstdio>
#include <iostream>
using namespace std;

void convert_string(int x,char str[]);
void convert_binary(int x,char str[]);
void convert_octal(int x,char str[]);
int judge_palindrome_number(char str[]);

int main()
{
	int i,j,t1,t2,t3,flag = 0,n;
	char a[100], b[100], c[100];
	
	scanf("%d",&n);
	
	convert_string(n,a);
	t1=judge_palindrome_number(a);
	if(1==t1) 
	{
		convert_binary(n,b);
		t2=judge_palindrome_number(b);
        if(1==t2)
        {
        	convert_octal(n,c);
        	t3=judge_palindrome_number(c);
        	if(1==t3)	
			{
				flag = 1;
				printf("Yes %s %s %s", a, b, c); 
			}       	
        }
	}
	if(!flag) printf("No");
	
	return 0;
}

void convert_string(int x,char str[])
{
	int t,i;
	
	t=x;
	if(t==0)
	{
	  str[0]='0';
	  str[1]='\0';
    }
	else 
	{
		i=0;
		while(t)
		{
			str[i]=t%10+48;
			t=t/10;
			i++;
		}
		str[i]='\0';
	}
	
	return;
}

void convert_binary(int x,char str[])
{
	int i;
	
	i=0;
	while(x>0)
	{
		str[i++]=x%2+48;
		x/=2;
	}
	if(0==x) str[i]='\0';
	
	return;
}

void convert_octal(int x,char str[])
{
	int i;
	
	i=0;
	while(x>0)
	{
		str[i++]=x%8+48;
		x/=8;
	}
	if(0==x) str[i]='\0';
	
	return;
}

int judge_palindrome_number(char str[])
{
	int i,j;
	
	i=0;
	while(str[i++]!='\0');
	j=i-2;
	i=0;
	while((str[i]==str[j])&&(i<=j))
	{
		i++;
		j--;
	}
	if(i>j)  return 1;
	else  return 0;
}

