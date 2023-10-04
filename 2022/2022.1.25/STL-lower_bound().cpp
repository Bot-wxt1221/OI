#include<bits/stdc++.h>
using namespace std;
#define MAX   100    //����10000000
#define MIN  -100
int a[MAX];          //���MAX����100�򣬴�����a[MAX]��ö���Ϊȫ�֡�
//�����鶨����ȫ�ֵ�ԭ���ǣ��е����⻷����ջ�ռ��С�������鶨���ھֲ�ռ����ջ�ռ䵼�±�ջ��
//���ڸ���OJ�ͱ����������ñ�������ʹջ�ռ�����ڴ��С��������ֱ�ջ��

unsigned long ulrand(){          //����һ���������
    return (
      (((unsigned long)rand()<<24)& 0xFF000000ul)
     |(((unsigned long)rand()<<12)& 0x00FFF000ul)
     |(((unsigned long)rand())    & 0x00000FFFul));
}

int bin_search(int *a, int n, int x){    //a[0]��a[n-1]�������
    int left = 0, right = n;             //���� n-1
    while (left < right) {
        int mid = left+(right-left)/2;   //int mid = (left+ right)>>1;
        if (a[mid] >= x)  right = mid;
        else    left = mid + 1;
    }
   return left;       //����������������a[n-1] < key��left = n
}

int main(){
    int n = MAX;
    srand(time(0));
    while(1){
        for(int i=0; i< n; i++)   //����[MIN, MAX]�ڵ�������������и�
            a[i] = ulrand() % (MAX-MIN + 1) + MIN;
        sort(a, a + n );       //����a[0]~a[n-1]

        int test = ulrand() % (MAX-MIN + 1) + MIN; //����һ�������x
        int ans = bin_search(a,n,test);
        int pos = lower_bound(a,a+n,test)-a;  

        //�Ƚ�bin_search()��lower_bound()������Ƿ�һ�£�
        if(ans == pos) cout << "!";             //��ȷ
        else        {  cout << "wrong"; break;} //�д��˳�
    }
}
