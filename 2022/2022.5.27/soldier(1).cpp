#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

int main() {
	freopen("soldier.in", "r", stdin);
	freopen("soldier.out", "w", stdout);
    int T, n;
    list<int> a;
    list<int>::iterator it; 
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        a.clear();
        int k = 2; //��һ��ɾ����2���� 
        for(int i = 1; i <= n; i++)
            a.push_back(i); //��ÿ��ʿ���ı��
        while(a.size() > 3){
            int cnt = 1;
            for(it = a.begin(); it != a.end(); ) {
                if(cnt++ % k == 0)//ɾ������k����ʿ�� 
                    it = a.erase(it);//itָ����һ���ĵ�ַ 
                else
                    it++;//itָ����һλ�ĵ�ַ 
            }
            k = (k == 2 ? 3 : 2); 
        }
        for(it = a.begin(); it != a.end(); it++) {
            if(it != a.begin()) printf(" "); 
            printf("%d", *it);
        }
        printf("\n");
    }
    return 0;
}
