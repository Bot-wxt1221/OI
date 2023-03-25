#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dx [] = { 1, 1, 0, -1, -1, -1, 0, 1 };//x������ı� 
int dy [] = { 1, 0, 1, 1, 0, -1, -1, -1 };//y������ı� 
int main () {
//	freopen ( ".in", "r", stdin );
//	freopen ( ".out", "w", stdout );
	int n, m, x, y;
	scanf ( "%d%d", &n, &m );//�Թ������� 
	char maze [ n + 2 ] [ m + 2 ];//������� 
	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0; j < m; j ++ ) {
			cin >> maze [ i ] [ j ];//�����Թ���ʼֵ 
			if ( maze [ i ] [ j ] == 'S' ) {//��� 
				x = i;
				y = j;
			} 
		}
	}
	int ans = 0, lj [ n * m + 10 ] [ 2 ];
	while ( 1 ) {
		if ( maze [ x ] [ y ] == 'E' ) {
			lj [ ans ] [ 0 ] = x;
			lj [ ans ] [ 1 ] = y;
			break;
		}//��������յ㣬������ѭ�� 
		bool tof = false;//��¼�Ƿ��߶� 
		for ( int i = 0; i < 8; i ++ ) {
			if ( maze [ x + dx [ i ] ] [ y + dy [ i ] ] == '0' || maze [ x + dx [ i ] ] [ y + dy [ i ] ] == 'E' ) {//����пյ� 
				maze [ x ] [ y ] = '2';//����߹� 
				lj [ ans ] [ 0 ] = x;//��¼ 
				lj [ ans ] [ 1 ] = y;//ͬ�� 
				x += dx [ i ];//x�ı� 
				y += dy [ i ];//y�ı� 
				tof = true;//��¼�Ѿ��߹� 
				ans ++;//����+1 
				break;//������ʡʱ�� 
			}
		}
		if ( ! tof ) {//���û���߶� 
			for ( int i = 0; i < 8; i ++ ) {
				if ( maze [ x + dx [ i ] ] [ y + dy [ i ] ] == '2' || maze [ x + dx [ i ] ] [ y + dy [ i ] ] == 'S' ) {//���� 
					maze [ x ] [ y ] = '1';//��·��ͨ 
					x += dx [ i ];//x�ı� 
					y += dy [ i ];//y�ı� 
					tof = true;//��¼�Ѿ��߹� 
					ans --;//����-1 
					break;//������ʡʱ�� 
				}
			}
		}
		if ( ! tof ) {//�����Ҳ�߲��� 
			printf ( "I'm stuck!\n" );//�޽� 
			return 0;
		}
	}
	for ( int i = 0; i <= ans; i ++ ) {//�������ѭ����һ���н� 
		printf ( "%d %d\n", lj [ i ] [ 0 ], lj [ i ] [ 1 ] );
	}
	printf ( "%d\n", ans );//�������ܲ��� 
//	fclose ( stdin );
//	fclose ( stdout );
	return 0;
}
