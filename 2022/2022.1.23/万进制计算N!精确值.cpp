#include <cstdio>
  
int a[10005];  

int main()  
{  
    int n;  
  
    while(scanf("%d",&n)==1)  
    {  
        int index,temp,i,j;  
        a[0]=1;  
        index=0;      //阶乘结果总长度  
        for(i=1;i<=n;i++)  
        {  
            temp=0;   //进位  
            for(j=0;j<=index;j++)  
            {                           
                a[j]=a[j]*i+temp;  
                temp=a[j]/10000;  
                a[j]%=10000;  
            }  

            if(temp>0)  //如果产生进位，把进位存到下一个a[i]
            {             
            	a[++index]=temp;  
            }  
        }  
        printf("%d",a[index]);  
        for(i=index-1;i>=0;i--)  
        {                               //不满4位的前边补0  
            if(a[i]>=1000)  
            	printf("%d",a[i]);  
            else if(a[i]>=100)  
            	printf("0%d",a[i]);  
            else if(a[i]>=10)  
            	printf("00%d",a[i]);  
            else  
                printf("000%d",a[i]);  
        }  
          printf("\n");  
    }  
    return 0;  
}  
