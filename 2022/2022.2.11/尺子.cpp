#include <cstdio>
//#include <cstdlib>  //abs求整数绝对值，c是定义在stdlib，而fabs是定义在math里 
//#include <cmath> //fabs建议使用 
#include <algorithm> //也定义了绝对值函数，建议C++使用这样的头文件 
using namespace std;

int main()
{
	int n;
	int a[8], b[35];
	int total = 0;
	
	scanf("%d", &n);
		
	for(a[1] = 1; a[1] < n - 6; a[1]++)
	  for(a[2] = a[1] + 1; a[2] < n - 5; a[2]++)
		 for(a[3] = a[2] + 1; a[3] < n - 4; a[3]++)
			for(a[4] = a[3] + 1; a[4] < n - 3; a[4]++)
			   for(a[5] = a[4] + 1; a[5] < n - 2; a[5]++)
				   for(a[6] = a[5] + 1; a[6] < n - 1; a[6]++)
				      for(a[7] = a[6] + 1; a[7] < n; a[7]++) {
				          	for(int i = 1; i <= n; i++)  b[i] = 0;
				           	for(int i = 1; i <= 7; i++) {
				          		b[n] = 1; b[a[i]] = 1; b[n - a[i]] = 1;				          	
				          		for(int j = i + 1; j <= 7; j++)
									b[abs(a[j] - a[i])] = 1;
						    }				            
							int t = 0;
				           	for(int i = 1; i <= n; i++)  t += b[i];
				           	if(t == n){
							//	for(i=1;i<=7;i++)
					        //   	    printf("%-3d",a[i]);
					        //  	printf("\n");
								for(int i = 7; i >= 1; i--) printf("%-3d",n-a[i]);	   
					            printf("\n");
					            int flag = 0;
					       		for(int i = 1; i <= 4; i++){
					       			if(a[i] != n - a[8-i]){
					       				flag = 1;
					       				break;
					       			}
					       		}									
								if(flag) total++; else total += 2;							
							} 
					  }
	printf("%d", total/2);

	return 0;	
}
