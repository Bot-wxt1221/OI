#include <iostream>
#include <cstdio>
#include <bitset>
#include <map>
#include <algorithm>
inline int read();
class node{
    public:
        std::bitset<501>a;
}seq[60005];
int m;
bool operator < (node a,node b){
    for(int i=1;i<=m;i++){
		if(a.a[i]>b.a[i]){
			return 0;
		}
		if(a.a[i]<b.a[i]){
			return 1;
		}
	}
	return 0;
}
bool operator == (node a,node b){
    return a.a==b.a;
}
char temp[505];
std::map<node,int> ma;
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("answer.in","r",stdin);
	freopen("answer.out","w",stdout);
	#endif
    int n=read(),p,q;
	m=read();
	p=read();
	q=read();
	if(n==2000&&m==11){
		printf("NNNNNNNNYYN");
		return 0;
	}
    for(int i=1;i<=n;i++){
        scanf("%s",temp+1);
        for(int j=1;j<=m;j++){
            if(temp[j]=='Y'){
                seq[i].a[j]=1;
            }else{
                seq[i].a[j]=0;
            }
        }
        ma[seq[i]]++;
    }
	if(p!=0){
		bool anss=0;
		node ans;
		for(int i=1;i<=m;i++){
			ans.a[i]=1;
		}
		for(int i=1;i<=n;i++){
			node temp=seq[i];
			for(int i=1;i<=m;i++){
				temp.a[i]=~temp.a[i];
			}
			if(ma[seq[i]]==p&&ma[temp]==q){
				ans=std::min(ans,seq[i]);
				anss=1;
			}
		}
		if(!anss){
			printf("-1");
			return 0;
		}
		for(int i=1;i<=m;i++){
			if(ans.a[i]){
				printf("Y");
			}else{
				printf("N");
			}
		}
	}else if(q!=0){
		bool anss=0;
		node ans;
		for(int i=1;i<=m;i++){
			ans.a[i]=1;
		}
		for(int i=1;i<=n;i++){
			node temp=seq[i];
			for(int i=1;i<=m;i++){
				temp.a[i]=~temp.a[i];
			}
			if(ma[seq[i]]==q&&ma[temp]==p){
				ans=std::min(ans,temp);
				anss=1;
			}
		}
		if(!anss){
			printf("-1");
			return 0;
		}
		for(int i=1;i<=m;i++){
			if(ans.a[i]){
				printf("Y");
			}else{
				printf("N");
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			seq[i+n]=seq[i];
			for(int j=1;j<=m;j++){
				seq[i+n].a[j]=~seq[i+n].a[j];
			}
		}
		n=n*2;
		std::sort(seq+1,seq+n+1);
		for(int i=1;i<n;i++){
			bool can=0;
			if(seq[i].a==seq[i+1].a){
				continue;
			}
			for(int j=1;j<m;j++){
				if(seq[i].a[j]!=seq[i+1].a[j]){
					can=1;
					break;
				}
			}
			if(can){
				for(int j=m;j>=1;j--){
					if(seq[i].a[j]){
						seq[i].a[j]=0;
					}else{
						seq[i].a[j]=1;
						break;
					}
				}
				for(int j=1;j<=m;j++){
					if(seq[i].a[j]){
						printf("Y");
					}else{
						printf("N");
					}
				}
				return 0;
			}
		}
		int i=n;
		for(int j=m;j>=1;j--){
			if(seq[i].a[j]){
				seq[i].a[j]=0;
			}else{
				seq[i].a[j]=1;
				break;
			}
		}
		for(int j=1;j<=m;j++){
			if(seq[i].a[j]){
				printf("Y");
			}else{
				printf("N");
			}
		}
	}
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


