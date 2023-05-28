#include <cstdio>
#include <iostream>
using namespace std;
//标记法判重 
int main()
{
	int a[10],i,book[10]={0},sum;
	int total=0;
	
	for(a[1]=1;a[1]<=9;a[1]++) //第1个数的百位 
	    if(book[a[1]]==0) 
		{
		   book[a[1]]=1;
		   for(a[2]=1;a[2]<=9;a[2]++)  //第1个数的十位 
		   	  if(book[a[2]]==0)
		   	  {
		   	  	 book[a[2]]=1;
				 for(a[3]=1;a[3]<=9;a[3]++)  //第1个数的个位 
				 	if(book[a[3]]==0)
				 	{
				 		book[a[3]]=1;
				 		for(a[4]=1;a[4]<=9;a[4]++)  //第2个数的百位 
				 			if(book[a[4]]==0)
				 			{
				 				book[a[4]]=1;
				 				for(a[5]=1;a[5]<=9;a[5]++)  //第2个数的十位 
									if(book[a[5]]==0)
									{
									    book[a[5]]=1;
									    for(a[6]=1;a[6]<=9;a[6]++)  //第2个数的个位 
									    	if(book[a[6]]==0)
									    	{
									    		book[a[6]]=1;
									    		for(a[7]=1;a[7]<=9;a[7]++)  //第3个数的百位 
									    			if(book[a[7]]==0)
									    			{
									    				book[a[7]]=1;
									    				for(a[8]=1;a[8]<=9;a[8]++)  //第3个数的十位 
															if(book[a[8]]==0)
															{
																book[a[8]]=1;
																for(a[9]=1;a[9]<=9;a[9]++)  //第3个数的个位 
																	if(book[a[9]]==0)
																	{
																		book[a[9]]=1;
																		sum=0;
																		for(i=1;i<=9;i++)
																			sum+=book[i];
																		//如果正好出现了9个不同的数，并且满足等式条件，则输出
																		if((9==sum) && ((a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6])==(a[7]*100+a[8]*10+a[9])))
																		{
																			total++;
																			printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
																		} 
																		book[a[9]]=0;
																	}
																book[a[8]]=0;
															}								    				
									    				book[a[7]]=0;
									    			}
									    		book[a[6]]=0;
									    	}
									    book[a[5]]=0;
									}				 				
				 				book[a[4]]=0;
				 			}
				 		book[a[3]]=0;
				 	}
				 book[a[2]]=0;	
		   	  }
		   	book[a[1]]=0;  
		}
	
	printf("total=%d",total/2);
	
	return 0;
}

