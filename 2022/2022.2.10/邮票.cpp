#include <cstdio>
#include <iostream>
using namespace std;

int n;
int number(int a,int b,int c,int d);

int main()
{
	int a,b,c,d;
	int num_max,num;
	
	scanf("%d",&n);
	a=1;
	num_max=0;
	for(b=a+1;b<=n*a+1;b++)
	  for(c=b+1;c<=n*b+1;c++)
	    for(d=c+1;d<=n*c+1;d++)
	    {
	    	num=number(a,b,c,d);
	    	if(num>num_max)
	    	{
	    		num_max=num;
				printf("%d %d %d %d ",a,b,c,d);
	    		printf("num=%d\n",num);
	    	}
	    }

	return 0;
}

int number(int a,int b,int c,int d)
{
	int sum,st[20000]={0};
	int n1,n2,n3,n4;
	
	for(n1=0;n1<=n;n1++)
	  for(n2=0;n2<=n-n1;n2++)
	    for(n3=0;n3<=n-n1-n2;n3++)
	      for(n4=0;n4<=n-n1-n2-n3;n4++)
	      {
	      	sum=n1*a+n2*b+n3*c+n4*d;
	      	st[sum]=1;
	      }
	sum=1;
	while(st[sum])
		sum++;
	
	return sum-1;	
}
