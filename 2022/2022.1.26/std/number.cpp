/*
   按照快速排序的思想，把数组前k大的数放到数组末尾。然后在对数组末尾 k个元素做排序再输出该部分元素。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

void swap(int & a,int & b)
{  int tmp = a;  a = b;  b = tmp;  }

//将a[]数组下标区间[start,end]前k大的数放到数组下标在[start,end]范围的末尾部分.
void FindMaxK(int a[],int start,int End,int k)
{
    if(start-End+1==k) return;//若是元素个数刚好就是k个，则可以直接返回. 
    int i=start,j=End,key=a[start];
    while(i<j)
    {
        while(i<j&&a[j]>=key) --j;
        swap(a[i],a[j]);
        while(i<j&&a[i]<=key) ++i;
        swap(a[i],a[j]);
    }
    if(End-i+1==k) return;//数组后半段的元素个数为End-i+1,刚好够k个 
    else if( End-i+1 > k) FindMaxK(a,i+1,End,k);//数组后半段的元素个数多于k个 
    else FindMaxK(a,start,i-1,k-(End-i+1) );//数组后半段元素个数不够k个。所以要在前半段继续寻找k-（End-i+1）这么多个。 
}

int main()
{
    int n,k;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i < n; ++i) scanf("%d",&a[i]);
    scanf("%d",&k);
    
    FindMaxK(a,0,n-1,k);

    sort(a+n-k-1,a+n);
    for(int i = n-1; i >= n-k; --i)
        printf("%d\n",a[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
