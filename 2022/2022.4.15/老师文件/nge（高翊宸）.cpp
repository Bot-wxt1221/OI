/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
#define file
using namespace std;
inline int read();
int arr[3000000];
int main(){
	#ifdef file
	freopen("nge.in", "r", stdin);
	freopen("nge.out", "w", stdout);
	#endif

	int n=read();
	
	//read
	for(int i=0;i<n;i++){
		arr[i]=read();
	}
	
	for(int i=0;i<n;i++){//i->n��f(i)���� 
		for(int j=i+1;j<n;j++){//Ѱ�� �����е�i��Ԫ��֮���һ������ai��Ԫ��--j 
			if(arr[j]>arr[i]){//���ajԪ�ش���ai��� 
				printf("%d ",j+1);
				goto loop;//û�ҵ���0�Ĵ��� ˳�����break 
			}
		}
		printf("0 ");//ûgoto--û�ҵ� 
		loop:;
	}

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
