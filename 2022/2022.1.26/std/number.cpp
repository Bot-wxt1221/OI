/*
   ���տ��������˼�룬������ǰk������ŵ�����ĩβ��Ȼ���ڶ�����ĩβ k��Ԫ��������������ò���Ԫ�ء�
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];

void swap(int & a,int & b)
{  int tmp = a;  a = b;  b = tmp;  }

//��a[]�����±�����[start,end]ǰk������ŵ������±���[start,end]��Χ��ĩβ����.
void FindMaxK(int a[],int start,int End,int k)
{
    if(start-End+1==k) return;//����Ԫ�ظ����պþ���k���������ֱ�ӷ���. 
    int i=start,j=End,key=a[start];
    while(i<j)
    {
        while(i<j&&a[j]>=key) --j;
        swap(a[i],a[j]);
        while(i<j&&a[i]<=key) ++i;
        swap(a[i],a[j]);
    }
    if(End-i+1==k) return;//������ε�Ԫ�ظ���ΪEnd-i+1,�պù�k�� 
    else if( End-i+1 > k) FindMaxK(a,i+1,End,k);//������ε�Ԫ�ظ�������k�� 
    else FindMaxK(a,start,i-1,k-(End-i+1) );//�������Ԫ�ظ�������k��������Ҫ��ǰ��μ���Ѱ��k-��End-i+1����ô����� 
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
