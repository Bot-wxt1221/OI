/*
�����˱Ƚ϶��ѭ�������ܲ�����ô��...
*/ 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
int x [ 20010 ];
int main () {
	freopen ( "rain.in", "r", stdin );
	freopen ( "rain.out", "w", stdout );
	int ans = 0, cnt = 0, maxn = -1, j, i = 0;
	while ( cin >> x [ i ] ) {//���� 
		if ( maxn <= x [ i ] ) {//�ж��Ƿ�ϸ� 
			maxn = x [ i ];//��ֵ 
			ans += cnt;//��cnt����ans 
			j = i;//Ϊ��������������׼�� 
			cnt = 0;//cnt��� 
		}else{//���� 
			cnt += maxn - x [ i ];//���밴��߸߶ȿ��Խӵ�ˮ 
		}
		i ++;//�ж��ܸ��� 
	}
	while ( cnt != 0 ) {//������滹�п��������Ŀռ� 
		maxn --;//��߸߶Ƚ��� 
		cnt = 0;//�������� 
		for ( int k = j + 1; k < i; k ++ ) {//�������ϴ�һ�� 
			if ( maxn <= x [ k ] ) {
				maxn = x [ k ];
				ans += cnt;
				j = k;
				cnt = 0;
			}else{
				cnt += maxn - x [ k ];
			}
		}
	}
	printf ( "%d\n", ans );//��� 
	fclose ( stdin );
	fclose ( stdout );
	return 0;
}
