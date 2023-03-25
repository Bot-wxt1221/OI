#include <stdio.h>
#include <iostream>
const int MAX = 50010;
int a[MAX];
using namespace std;
int deleteNum(int n, int mid) {//统计相邻岩石距离小于mid的个数，即需要删掉的删掉的岩石个数
    int cnt = 0, last = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] - a[last] < mid) {
            cnt++;
        }
        else {
            last = i;
        }
    }
    return cnt;
}

int main() {
    int L, n, m;
    freopen("house.in","r",stdin);
    freopen("house.out","w",stdout);
    scanf("%d%d%d", &L, &n, &m);
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a+1,a+n+1);
    n++;
    a[n] = L;
    int left = 0, right = L;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int num = deleteNum(n, mid);
        if(num > m) {//如果岩石距离不大于mid，需要删除的岩石大于m，则需要减小求的距离值的上限，寻找更小的目标值
            right = mid - 1;
        }
        else {//如果岩石距离不大于mid，需要删除的岩石不大于m，则可以增大距离值的下限，看能否求得更大的值
            left = mid + 1;
        }
    }
    printf("%d", right);
    return 0;
}
