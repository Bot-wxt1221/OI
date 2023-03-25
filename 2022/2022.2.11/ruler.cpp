#include <cstdio>
#include <cstdlib>
#define SIZE 40

void dfs(int len, int step);
int n, k, a[SIZE], total=0;

int main(){
//	freopen("ruler.in", "r", stdin);
//	freopen("ruler.out", "w", stdout);
	scanf("%d %d", &n, &k);
	dfs(1, 1);	
	printf("%d", total/2);

	return 0;	
}

void dfs(int len, int step){
	int b[SIZE];
	if(len > n) return;
	if(step == k + 1){
		for(int i = 1; i <= n; i++) b[i] = 0;
       	for(int i = 1; i <= k; i++) {
      		b[n] = 1; b[a[i]] = 1; b[n - a[i]] = 1;				          	
      		for(int j = i + 1; j <= k; j++)	b[abs(a[j] - a[i])] = 1;
      	}
  		int t = 0;
       	for(int i = 1; i <= n; i++)	t += b[i];
       	if(t == n) {
		//	for(i=1;i<=7;i++)
        //   	    printf("%-3d",a[i]);
        //  	printf("\n");
		//	for(i=7;i>=1;i--)
        //      printf("%-3d",n-a[i]);	   
        //    printf("\n");
            int flag = 0;
       		for(int i = 1; i <= k + 1 - i; i++)
       			if(a[i] != n - a[k + 1 - i])
       			{
       				flag = 1;
       				break;
       			}
			if(flag)
				total++;
			else
				total += 2;	
		} 
		return;
	}

	for(a[step] = len; a[step] < n - k + step; a[step]++)
		dfs(a[step] + 1, step + 1);				
	
	return;
}
