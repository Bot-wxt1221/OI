/*
̰�ģ����ɨ�������е�Ԫ�أ��ۼӡ�
��һ������ʱ���ͻ����ӣ���һ������ʱ���ͻ���١�
�����ǰ�õ��ĺͱ���˸���������������ڽ��������ۼ��У�����ٺ������͡�
����������������һλ�ÿ�ʼ������͡�
*/ 

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("maxsum.in", "r", stdin);
	freopen("maxsum.out", "w", stdout);
	const int INF = 0x7fffffff;

	int t; cin >> t; //������������
	for(int i = 1; i <= t; i++){
		int n; cin >> n;
		int maxsum = -INF; //�������ͣ���ʼ��Ϊһ����С����
		int start = 1, end = 1, p = 1; //��㣬�յ㣬ɨ��λ��
		int sum = 0; //�����
		for(int j = 1; j <= n; j++){
			int a; cin >> a; //����һ��Ԫ��		
			sum += a;
			if(sum > maxsum){
				maxsum = sum;
				start = p;
				end = j;
			}
			if(sum < 0){
				//ɨ��j ʱ��ǰ������������Ǹ�������ô����һ�� j ���¿�ʼ��͡�
				sum = 0;
				p = j + 1;
			}
		}
		//printf("Case %d:\n",i);
		//printf("%d %d %d\n", maxsum, start, end);
		cout << "Case " << i << ":\n";
		cout << maxsum << " " << start << " " << end << "\n";
		if(i != t) cout << "\n";
	}	
	return 0;
}

/*
����:
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5

���:
Case 1:
14 1 4

Case 2:
7 1 6
*/

