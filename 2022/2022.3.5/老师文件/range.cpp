/*
���㷨������
�㷨ģ�ͣ���n��������[ai,bi], ��������ѡ�����ٵĵ�,ʹÿ��������������һ���㡣
�㷨�����Ȱ�b1<=b2<=...<=bn����ÿ�α�ǵ�ǰ������Ҷ˵�x�������Ƶ�ǰ����ָ�룬ֱ����ǰ���䲻����x,���ظ�����������
*/
#include <iostream>
#include <cstdio>
using namespace std;
int a[10001],b[10001],sum=0,n,m;

void qsort(int x,int y)          //��ؼ��ֿ���
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
  for(int i=1,x=-1;i<=n;++i)    //�ڳ�ʼ��ѭ��������ͬʱ����ʼ��x����x=-1����ʹ��һ����������������Ĳ�����ͬ��
  {
       if (x>=a[i]) continue;      //�����ǰ���������ǵ㣬��������
       ++sum;   x=b[i];             //���±�ǵ㡣
  }
  cout<<sum<<endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}

