//��С������(Kruskal����̰��˼��) 
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
int fa[MAXN];
int n, m;
struct edge{
    int u, v, w;
} e[MAXN*MAXN];

bool cmp(edge x, edge y){
    return x.w < y.w;
}

void init(int n) {//���鼯��ʼ�����Ϻ�Ϊ���� 
	for(int i = 1; i <= n; i++){
	fa[i] = i;
	}
    return;  
}

bool Merge(int a, int b) { //�ϲ� 
    int p = fa[a];
    int q = fa[b];
    if(p == q) return false;
    for(int i = 1; i <= n; i++) { //������н�㣬�Ѽ��Ϻ��� q �ĸ�Ϊ p
		if(fa[i] == q) {
			fa[i] = p;  //a�ļ��ϺŸ�ֵ��b���Ϻ�
		}			
    }
    return true;
}

int Kruskal(int n) { //����С�������ı�Ȩֵ�� 
    int ans = 0;
    sort(e + 1, e + m + 1, cmp);
    for(int i = 1; i <= m; i++) {
    	if(Merge(e[i].u, e[i].v)) {
            ans += e[i].w;
            n--;
            if(n == 1) { //n-1�κϲ��㷨���� 
				return ans;
			}
        }
    }        
    return 0;
}

int main() {
    cin >> n >> m;
    init(n);
    for(int i = 1; i <= m; i++) {
    	cin >> e[i].u >> e[i].v >> e[i].w;
    }
        
    cout << Kruskal(n);
    return 0;
}
/*����
7 12
1 2 23
1 6 28
1 7 36
2 3 20
2 7 1
3 4 15
3 7 4
4 5 3
4 7 9
5 6 17
5 7 16
6 7 25

���
57 
*/
