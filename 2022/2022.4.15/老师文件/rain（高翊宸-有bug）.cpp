/***
 * @Author: Zi_Gao
 * @Description: 
6
4 2 0 3 2 5

12
0 1 0 2 1 0 1 3 2 1 2 1
 */
#include <cstdio>
#define file
using namespace std;
inline int read();
int arr[30000];
int main(){
	#ifdef file
	freopen("rain.in", "r", stdin);
	freopen("rain.out", "w", stdout);
	#endif

	int n=0;
	
	//read
	while(~scanf("%d",&arr[n])){
		n++;
	}

	int out=0;
	for(int i=0;i<n;){//计算第i个点为起始的水洼的蓄水量 
		int cnt=0;//记录当前的水洼的蓄水量 
		int j;//记录当前扫到的点 
		for(j=i+1;j<=n;j++){
			if(arr[i]<=arr[j]){//如果找到可能的结束点 记录一遍 
				i=j;//调到这个点 
				out+=cnt;//累加蓄水量 
				goto loop;
			}
			cnt+=arr[i]-arr[j];//累加当前水洼的蓄水量 
		}
		arr[i]--;//如果不行就当前的高度减去尝试 
		loop:;
	}
	
	printf("%d",out);

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
