/*
奇数个数时，a1<a2<...<ak...<an,k=n/2+1
a=a1 a2...ak
b=an an-1...ak+1
*/
/*
偶数个数时， a1<a2<...<ak...<an,k=n/2
选a i - a i-1 的最小值
详见代码 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	freopen("mindistance.in","r",stdin);
	freopen("mindistance.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++){
		int aa[11];
		bool vised[11];
		memset(aa,0,sizeof(aa));
		memset(vised,0,sizeof(vised));
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>aa[j];
		}
		if(n==2){
			cout<<abs((aa[1])-(aa[2]))<<endl;
		}else if(n%2==1){
			sort(aa+1,aa+n+1);
			int k=(n/2)+1;
			int a=0,b=0;
			if(aa[1]==0){
				swap(aa[1],aa[2]);
			}
			for(int i=1;i<=k;i++){
				a=a*10+aa[i];
			}
			for(int i=n;i>k;i--){
				b=b*10+aa[i];
			}
			cout<<a-b<<endl;
		}else{
		
			sort(aa+1,aa+n+1);
			int  _min=987654322,_mini=0;
			for(int j=aa[1]==0?2:1;j<n;j++){	memset(vised,0,sizeof(vised));
					_mini=j;
			int choose=2,a=aa[_mini],b=aa[_mini+1];
			vised[_mini]=vised[_mini+1]=1;
			while(choose<n){
				choose+=2;
				int i=1;
				while(1){
					if(!vised[i]){
						break;
					}
					i++;
				}
				vised[i]=1;
				b=b*10+aa[i];
				i=n;
				while(1){
					if(!vised[i]){
						break;
					}
					i--;
				}
				vised[i]=1;
				a=a*10+aa[i];
			}
			_min=min(_min,(b-a)); 
			}
	cout<<_min<<endl;
		}
	}
	return 0;
}

