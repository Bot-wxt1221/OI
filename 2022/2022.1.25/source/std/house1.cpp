#include <stdio.h>
#include <iostream>
const int MAX = 50010;
int a[MAX];
using namespace std;
int deleteNum(int n, int mid) {//ͳ��������ʯ����С��mid�ĸ���������Ҫɾ����ɾ������ʯ����
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
        if(num > m) {//�����ʯ���벻����mid����Ҫɾ������ʯ����m������Ҫ��С��ľ���ֵ�����ޣ�Ѱ�Ҹ�С��Ŀ��ֵ
            right = mid - 1;
        }
        else {//�����ʯ���벻����mid����Ҫɾ������ʯ������m��������������ֵ�����ޣ����ܷ���ø����ֵ
            left = mid + 1;
        }
    }
    printf("%d", right);
    return 0;
}
