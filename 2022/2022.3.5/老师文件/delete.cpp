/*
【算法分析】
由于正整数n的有效数位为240位，所以很自然地采用字符串类型存贮n。那么如何决定哪s位被删除呢？是不是最大的s个数字呢？
显然不是，大家很容易举出一些反例。为了尽可能逼近目标，我们选取的贪心策略为：每一步总是选择一个使剩下的数最小的
数字删去，即按高位到低位的顺序搜索，若各位数字递增，则删除最后一个数字；否则删除第一个递减区间的首字符，这样删一
位便形成了一个新数字串。然后回到串首，按上述规则再删下一个数字。重复以上过程s次为止，剩下的数字串便是问题的解了。
               例如：n=175438,  s=4
               删数的过程如下：
                  n=175438        //删掉7
                    15438          //删掉5
                    1438            //删掉4
                    138              //删掉8
                    13                //解为13


这样，删数问题就与如何寻找递减区间首字符这样一个简单的问题对应起来。不过还要注意一个细节性的问题，就是可能会出现
字符串串首有若干0的情况，甚至整个字符串都是0的情况。
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int le;
char n[255];

void del(int k)
{
	int i;
	for (i=k+1;i<=le-1;i++) n[i-1]=n[i];
	le--;
	
	return;
}

int main()
{
	int s,i;
	
	freopen("delete.in","r",stdin);
	freopen("delete.out","w",stdout);
	cin>>n;
	cin>>s;
	le=strlen(n);
	while (s>0)
	{
		i=0;
		while (i<le-1&&n[i]<=n[i+1]) i++;
		del(i);
		s--; 
	}
	while (le>1&&n[0]=='0') del(0);
	for (i=0;i<=le-1;i++) cout<<n[i];
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

