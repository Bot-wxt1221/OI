#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[205],d[205],ans[205];
char temp[205],n[205];
int jin[205];
string a,b;
int main(){
	freopen("a+b.in","r",stdin);
	freopen("a+b.out","w",stdout);
	cin>>a>>b;
	if(a[0]=='-'&&b[0]=='-'){
		cout<<'-';
	}
	if(a[0]=='-'){
		for (int i=1;i<a.size();i++) c[a.size()-i+1]=a[i]-48;
	}else{
		for (int i=0;i<a.size();i++) c[a.size()-i]=a[i]-48;
	}
	if(b[0]=='-'){
		for (int i=1;i<b.size();i++) d[a.size()-i+1]=b[i]-48;
	}else{
		for (int i=0;i<b.size();i++) d[a.size()-i]=b[i]-48;
	}
			int lenc=1;
	if((a[0]=='-'&&b[0]=='-')||('0'<=a[0]&&a[0]<='9'&&'0'<=b[0]&&b[0]<='9')){   
	if(a[0]=='-'){
		for(int i=0;i<a.size()-1;i++){
			temp[i]=a[i+1];
		}
		temp[a.size()-1]='\0';
		string temp2=temp;
		a=temp2;
	} 
	if(b[0]=='-'){
		for(int i=0;i<b.size()-1;i++){
			temp[i]=b[i+1];
		}
		temp[b.size()-1]='\0';
		string temp2=temp;
		b=temp2;
	}                                             
  	int lena=a.size();
  	int lenb=b.size();
  	for (int i=0;i<=lena-1;i++) c[lena-i]=a[i]-48;  
	for (int i=0;i<=lenb-1;i++) d[lenb-i]=b[i]-48;
  	int lenc =1;
  	int x=0;
  	while (lenc <=lena||lenc <=lenb)
	{
		ans[lenc]=c[lenc]+d[lenc]+x;   
		x=ans[lenc]/10;
		ans[lenc]%=10;
		lenc++;
	}
	if(x!=0){
	cout<<x;   
	}
	while ((ans[lenc]==0)&&(lenc>1)) lenc--; 
	for (int i=lenc;i>=1;i--) 
		cout<<ans[i];                                  
		
	}else{
		string n1,n2;
		if(a[0]=='-'&&b[0]!='-'){
			string temp(a,1);
			n1=temp;
			n2=b;
		}else{
			string temp(b,1);
			n2=temp;
			n1=a;
		}
		if (n1.size()<n2.size()||(n1.size()==n2.size()&&strcmp(n1.c_str(),n2.c_str())<0))
			//strcmp()Ϊ�ַ����ȽϺ�������n1==n2, ����0;   n1>n2ʱ��������������n1<n2ʱ�����ظ�����
	{                                        //���������ͼ����������������ͼ���
		strcpy(n,(char*) n1.c_str());                //��n1�����ֵ��ȫ��ֵ��n����
		strcpy((char*) n1.c_str(),(char*) n2.c_str());
		strcpy((char*) n2.c_str(),n);
		cout<<"-";                    //�����˼����ͱ����������Ϊ����
	}   

	int lena=n1.size(); int lenb=n2.size();
	for (int i=0;i<=lena-1;i++) a[lena-i]=int(n1[i]-'0');  //����������a����
	for (int i=0;i<=lenb-1;i++) b[lenb-i]=int(n2[i]-'0');  //��������b����
    int i=1;
	while (i<=lena||i<=lenb)
	{
		if (a[i]<b[i])
		{
			a[i]+=10;               //����������ô���λ��1��10
			a[i+1]--;
		}
		c[i]=a[i]-b[i];                        //��Ӧλ���
		i++;
	}
	lenc=i;
	while ((c[lenc]==0)&&(lenc>1)) lenc--;   //���λ��0���������  
	for (i=lenc;i>=1;i--) cout<<c[i];               //������
	
	return 0;
}
}
