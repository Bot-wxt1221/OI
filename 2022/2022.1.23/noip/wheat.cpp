#include <iostream>
#include <cstdio>
using namespace std;
class in{
	public:
		char a[10005];
		in(){
			for(int i=0;i<10005;i++){
				a[i]='\0';
			}
		}
};
in mi(int b);
in c(in z,in y);
in ans;
int main(){
//	freopen("wheat.in","r",stdin);
//	freopen("wheat.out","w",stdout);
	int n;
	cin>>n;
	ans=mi(n);
	if(strlen(ans.a)>500){
	for(int i=strlen(ans.a)-501;i<strlen(ans.a)-1;i++){
		if(ans.a[i]==0){
			cout<<0;
			continue;
		}
		cout<<ans.a[i]-'0';
	}
		cout<<ans.a[strlen(ans.a)-1]-1-'0';
	}
	else{
		for(int i=1;i<=500-strlen(ans.a);i++){
			cout<<0;
		}
		for(int i=0;i<strlen(ans.a)-1;i++){
			cout<<ans.a[i];
		}
		cout<<ans.a[strlen(ans.a)-1]-1-'0';
	}
	return 0;
}
in mi(int b){
	if(b==0){
		in temp;
		temp.a[0]='1';
		return temp;
	}
	in temp=mi(b/2);
	in anss=c(temp,temp);
	if(b%2==1){
		in aa;
		aa.a[0]='2';
		in temp=c(anss,aa);
		in ans;
		if(strlen(temp.a)>500){
	for(int i=strlen(temp.a)-501;i<strlen(temp.a);i++){
		ans.a[i-(strlen(temp.a)-501)]=temp.a[i];
	}
	}
		else
			ans=temp;
		return ans;
	}
	in ans;
		if(strlen(temp.a)>500){
	for(int i=strlen(temp.a)-501;i<strlen(temp.a);i++){
		ans.a[i-(strlen(temp.a)-501)]=temp.a[i];
	}
	}
		else
			ans=anss;
	return ans;
	
}
in c(in z,in y){
	int x;
	int a[10005],b[10005],afs[10005];
	memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(afs,0,sizeof(afs));
	int lena=strlen(z.a);int lenb=strlen(y.a);
    for (int i=0;i<=lena-1;i++) a[lena-i]=z.a[i]-'0';
    for (int i=0;i<=lenb-1;i++) b[lenb-i]=y.a[i]-'0';
  	for (int i=1;i<=lena;i++)
	{
	     x=0;                                      //用于存放进位
	     for (int j=1;j<=lenb;j++)                     //对乘数的每一位进行处理
	     {
		   afs[i+j-1]=a[i]*b[j]+x+afs[i+j-1]; //当前乘积 +上次乘积进位 +原数	    	   
		   x=afs[i+j-1]/10;
		   afs[i+j-1] %= 10;
	     }
	     afs[i+lenb]=x;    //进位
	}
	int lenc=lena+lenb;
	while (afs[lenc]==0&&lenc>1)       //删除前导0
		lenc--;
	in temp;
	for(int i=lenc;i>=1;i--){
		temp.a[lenc-i]=afs[i]+'0';
	}
	return temp;
}
