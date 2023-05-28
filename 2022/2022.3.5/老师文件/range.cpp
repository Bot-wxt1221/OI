/*
【算法分析】
算法模型：给n个闭区间[ai,bi], 在数轴上选尽量少的点,使每个区间内至少有一个点。
算法：首先按b1<=b2<=...<=bn排序。每次标记当前区间的右端点x，并右移当前区间指针，直到当前区间不包含x,再重复上述操作。
*/
#include <iostream>
#include <cstdio>
using namespace std;
int a[10001],b[10001],sum=0,n,m;

void qsort(int x,int y)          //多关键字快排
{ 
  int i,j,mid1,mid2,t;
  i=x;j=y;mid1=b[(x+y)/2];mid2=a[(x+y)/2];
  while(i<=j)
  { 
     while(b[i]<mid1||((b[i]==mid1)&&(a[i]<mid2)))  ++i;
     while(b[j]>mid1||((b[j]==mid1)&&(a[j]>mid2)))  --j;
     if(i<=j)
     { 
	    t=b[j];b[j]=b[i];b[i]=t;
        t=a[j];a[j]=a[i];a[i]=t;
        ++i;  --j; 
     }
  }
  if(x<j) qsort(x,j);
  if(i<y) qsort(i,y);
  
  return;
}

int main()
{
  freopen("range.in","r",stdin);
  freopen("range.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
  qsort(1,n);
  for(int i=1,x=-1;i<=n;++i)    //在初始化循环变量的同时，初始化x。令x=-1可以使第一个区间与其他区间的操作相同。
  {
       if (x>=a[i]) continue;      //如果当前区间包含标记点，就跳过。
       ++sum;   x=b[i];             //更新标记点。
  }
  cout<<sum<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

