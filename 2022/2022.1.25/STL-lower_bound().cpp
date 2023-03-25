#include<bits/stdc++.h>
using namespace std;
#define MAX   100    //试试10000000
#define MIN  -100
int a[MAX];          //如果MAX超过100万，大数组a[MAX]最好定义为全局。
//大数组定义在全局的原因是：有的评测环境，栈空间很小，大数组定义在局部占用了栈空间导致爆栈。
//现在各大OJ和比赛都会设置编译命令使栈空间等于内存大小，不会出现爆栈。

unsigned long ulrand(){          //生成一个大随机数
    return (
      (((unsigned long)rand()<<24)& 0xFF000000ul)
     |(((unsigned long)rand()<<12)& 0x00FFF000ul)
     |(((unsigned long)rand())    & 0x00000FFFul));
}

int bin_search(int *a, int n, int x){    //a[0]～a[n-1]是有序的
    int left = 0, right = n;             //不是 n-1
    while (left < right) {
        int mid = left+(right-left)/2;   //int mid = (left+ right)>>1;
        if (a[mid] >= x)  right = mid;
        else    left = mid + 1;
    }
   return left;       //特殊情况：如果最后的a[n-1] < key，left = n
}

int main(){
    int n = MAX;
    srand(time(0));
    while(1){
        for(int i=0; i< n; i++)   //产生[MIN, MAX]内的随机数，有正有负
            a[i] = ulrand() % (MAX-MIN + 1) + MIN;
        sort(a, a + n );       //排序，a[0]~a[n-1]

        int test = ulrand() % (MAX-MIN + 1) + MIN; //产生一个随机的x
        int ans = bin_search(a,n,test);
        int pos = lower_bound(a,a+n,test)-a;  

        //比较bin_search()和lower_bound()的输出是否一致：
        if(ans == pos) cout << "!";             //正确
        else        {  cout << "wrong"; break;} //有错，退出
    }
}
