#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a1[100],b1[100];
  	int a[100],b[100],c[100],lena,lenb,lenc,i,x;
  	memset(a,0,sizeof(a));
  	memset(b,0,sizeof(b));
  	memset(c,0,sizeof(c));
  	gets(a1);
 	gets(b1);                                                     	//��������뱻����
  	lena=strlen(a1);
  	lenb=strlen(b1);
  	for (i=0;i<=lena-1;i++) a[lena-i]=a1[i]-48;    	//��������a����
	for (i=0;i<=lenb-1;i++) b[lenb-i]=b1[i]-48;  //��������b����
  	lenc =1;
  	x=0;
  	while (lenc <=lena||lenc <=lenb)
	{
		c[lenc]=a[lenc]+b[lenc]+x;     //�������
		x=c[lenc]/10;
		c[lenc]%=10;
		lenc++;
	}
	//c[lenc]=x; 
	//if (c[lenc]==0)
	//	lenc--;                                    //������߽�λ
	while ((c[lenc]==0)&&(lenc>1)) lenc--;   //���λ��0���������  
	for (i=lenc;i>=1;i--) 
		cout<<c[i];                                     //������
	cout<<endl;
	
	return 0;
} 

