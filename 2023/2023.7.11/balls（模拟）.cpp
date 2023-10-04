//不难发现，对于一个结点k，其左子结点、右子结点的编号分别是2k和2k+1
//直接模拟（超时），I高达可以高达2^D-1，每组测试数据下落总层数可能会
//高达219*19=9961472，而一共可能有10000组数据。

#include <bits/stdc++.h>
using namespace std;
const int maxd = 20;

int s[1<<maxd];   //最大结点个数为 2^maxd-1
                             
int main() {	
	int T, D, I;
	while(scanf("%d", &T) == 1 && T != -1) {
		while(T--) {
			scanf("%d%d", &D, &I); 
			memset(s, 0, sizeof(s));  //开关
			int k, n = (1<<D)-1;     //n是最大结点编号
			for(int i = 0; i < I; i++){  //连续让I个小球下落
				k = 1;
				for(;;) {
					s[k] = !s[k];
					k = s[k] ? k*2 : k*2+1; //根据开关状态选择下落方向
					if(k > n) break;    //已经落 “出界 ”了
				}                                              
			}                                                
			printf("%d\n", k/2);   //“出界”之前的叶子编号		
		}		
	}
	
	return 0;
} 
/*
Sample Input
5
4 2
3 4
10 1
2 2
8 128
-1

Sample Output
12
7
512
3
255
*/
 
