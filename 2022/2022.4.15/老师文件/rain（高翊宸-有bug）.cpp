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
	for(int i=0;i<n;){//�����i����Ϊ��ʼ��ˮ�ݵ���ˮ�� 
		int cnt=0;//��¼��ǰ��ˮ�ݵ���ˮ�� 
		int j;//��¼��ǰɨ���ĵ� 
		for(j=i+1;j<=n;j++){
			if(arr[i]<=arr[j]){//����ҵ����ܵĽ����� ��¼һ�� 
				i=j;//��������� 
				out+=cnt;//�ۼ���ˮ�� 
				goto loop;
			}
			cnt+=arr[i]-arr[j];//�ۼӵ�ǰˮ�ݵ���ˮ�� 
		}
		arr[i]--;//������о͵�ǰ�ĸ߶ȼ�ȥ���� 
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
