//高精度加法 
#include <iostream>
#include <cstdio>
using namespace std;
bool jin[105];//是否进位 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	string a,b;//数据太水了，string随便用 
	cin>>a>>b;
	if(a.size()>b.size()){//统一两个的位数 
		int c=a.size()-b.size();//运行时位数会变，故使用这个来存储   下同   
		for(int i=1;i<=c;i++){
			b='0'+b;
		}
	}else if(a.size()<b.size()){
		int c=b.size()-a.size();
		for(int i=1;i<=c;i++){
			a='0'+a;

		}
	}
	string c;//答案 
	for(int i=a.size()-1;i>=0;i--){
		int f=(a[i]-'0')+(b[i]-'0');//int避免越界 
		if(f>9||(f>8&&jin[i])){//是否向前进位 
			if(i!=0){
				jin[i-1]=1;//向前进位 
				f-=10;
			}else{
				cout<<1;//由于前面没有数位，所以先输出 1 代替进位 
				f-=10;
			}
		}
		if(jin[i])	f++;//进位 
		c=char(f+'0')+c;
	}
	cout<<c;
	return 0;
}

