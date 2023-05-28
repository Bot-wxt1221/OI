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
        int k = 2; //第一次删喊“2”的 
        for(int i = 1; i <= n; i++)
            a.push_back(i); //存每个士兵的编号
        while(a.size() > 3){
            int cnt = 1;
            for(it = a.begin(); it != a.end(); ) {
                if(cnt++ % k == 0)//删除喊“k”的士兵 
                    it = a.erase(it);//it指到下一个的地址 
                else
                    it++;//it指到下一位的地址 
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
