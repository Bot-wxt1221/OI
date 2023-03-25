#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h,i;
	int total=0;
	
	for(a=1;a<=9;a++) //第1个数的百位 
		for(b=1;b<=9;b++)  //第1个数的十位 
		    if(b!=a)
			{
				for(c=1;c<=9;c++)  //第1个数的个位 
					if(c!=a && c!=b)
					{
						for(d=1;d<=9;d++)  //第2个数的百位 
							if(d!=a && d!=b && d!=c)
							{
								for(e=1;e<=9;e++)  //第2个数的十位 
									if(e!=a && e!=b && e!=c && e!=d)
									{
										for(f=1;f<=9;f++)  //第2个数的个位 
											if(f!=a && f!=b && f!=c && f!=d && f!=e)
											{
												for(g=1;g<=9;g++)  //第3个数的百位 
													if(g!=a && g!=b && g!=c && g!=d && g!=e && g!=f)
													{
														for(h=1;h<=9;h++)  //第3个数的十位 
															if(h!=a && h!=b && h!=c && h!=d && h!=e && h!=f && h!=g)
															{
																for(i=1;i<=9;i++)  //第3个数的个位 
																	if(i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && i!=g && i!=h)
																	{
																		if((a*100+b*10+c+d*100+e*10+f)==(g*100+h*10+i))
																		{
																			total++;
																			printf("%d%d%d+%d%d%d=%d%d%d\n",a,b,c,d,e,f,g,h,i);
																		}		
																	}
															}
													}
											}
									}
							}
					}
					
				
			}
	printf("total=%d",total/2);
	
	return 0;
}

