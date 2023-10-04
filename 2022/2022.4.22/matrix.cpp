/***
 * @Author: Zi_Gao
 * @Description: 
10100
10111
11111
10010
 */
#include <cstdio>
#include <algorithm>
#define file
using namespace std;
inline int read();
int arr[2100][2100],mx[2100][2100];
int main(){
	#ifdef file
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	#endif

	char t;
	int inn=0,inm=0,cnt=0;
	int n=0,m=0;
	while(true){
		t=getchar();
		if(t==EOF){
			break;
		}
		if(t=='1'){
			arr[inn][inm]=1;
		}
		++inm;
		if(t=='\n'){
			m=max(m,inm);
			inm=0;
			++inn;
		}
	}
	
	n=inn+1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			mx[i][j+1]=arr[i][j]+mx[i][j];
		}
	}
//	
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=m;j++){
//			printf("%d ",mx[i][j]);
//		}
//		putchar('\n');
//	}

	for(int x1=0;x1<n;x1++){
		for(int y1=0;y1<m;y1++){
			if(arr[x1][y1]==0){
				continue;
			}
			for(int y2=y1;y2<m;y2++){
				if((mx[x1][y2+1]-mx[x1][y1])!=(y2-y1+1)){
					continue;
				}
				for(int x2=x1;x2<n;x2++){
					//��֤
					for(int i=x1;i<=x2;i++){
						if((mx[i][y2+1]-mx[i][y1])!=(y2-y1+1)){
							goto loop;
						}
					}
					cnt=max(cnt,(x2-x1+1)*(y2-y1+1));
					loop:;
				}
			}
		}
	}
	
	printf("%d",cnt);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
