//10^n-9^n
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
class in{
	public:
		char a[10005];
		in(){
			for(int i=0;i<=10004;i++){
				a[i]='\0';
			}
		}
};
in power(int a,int b);
in c(in a,in b);
int main(){
	freopen("wrongnumber.in","r",stdin);
	freopen("wrongnumber.out","w",stdout);
	int n;
	cin>>n;
	in ad=power(10,n);
		in bd=power(9,n);
	int sizea=strlen(ad.a),sizeb=strlen(bd.a);
	int a[10005],b[10005],c[10005];
	for (int i=0;i<=sizea-1;i++) a[sizea-i]=int(ad.a[i]-'0');  //被减数放入a数组
	for (int i=0;i<=sizeb-1;i++) b[sizeb-i]=int(bd.a[i]-'0');
	for(int i=0;i<sizea||i<sizeb;i++){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i];
	}
	int lenc=max(sizea,sizeb);
	while ((c[lenc]==0)&&(lenc>1)) lenc--;
	for(int i=lenc;i>0;i--){
		cout<<c[i];
	}
	return 0;
}
in power(int a,int b){
	if(b==0){
		in temp;
		temp.a[0]='1';
		return temp;
	}
	in temp=power(a,b/2);
	in ans=c(temp,temp);
	if(b%2==1){
		in aa;
		if(a==10){
			aa.a[0]='1';
			aa.a[1]='0';
		}else{
			aa.a[0]='9';
		}
		return c(ans,aa);
	}
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
