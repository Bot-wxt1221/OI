#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dx [] = { 1, 1, 0, -1, -1, -1, 0, 1 };//x轴坐标改变 
int dy [] = { 1, 0, 1, 1, 0, -1, -1, -1 };//y轴坐标改变 
int main () {
//	freopen ( ".in", "r", stdin );
//	freopen ( ".out", "w", stdout );
	int n, m, x, y;
	scanf ( "%d%d", &n, &m );//迷宫长、宽 
	char maze [ n + 2 ] [ m + 2 ];//标记数组 
	for ( int i = 0; i < n; i ++ ) {
		for ( int j = 0; j < m; j ++ ) {
			cin >> maze [ i ] [ j ];//输入迷宫初始值 
			if ( maze [ i ] [ j ] == 'S' ) {//起点 
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
		}//如果到达终点，则跳出循环 
		bool tof = false;//记录是否走动 
		for ( int i = 0; i < 8; i ++ ) {
			if ( maze [ x + dx [ i ] ] [ y + dy [ i ] ] == '0' || maze [ x + dx [ i ] ] [ y + dy [ i ] ] == 'E' ) {//如果有空地 
				maze [ x ] [ y ] = '2';//标记走过 
				lj [ ans ] [ 0 ] = x;//记录 
				lj [ ans ] [ 1 ] = y;//同上 
				x += dx [ i ];//x改变 
				y += dy [ i ];//y改变 
				tof = true;//记录已经走过 
				ans ++;//步数+1 
				break;//跳出节省时间 
			}
		}
		if ( ! tof ) {//如果没有走动 
			for ( int i = 0; i < 8; i ++ ) {
				if ( maze [ x + dx [ i ] ] [ y + dy [ i ] ] == '2' || maze [ x + dx [ i ] ] [ y + dy [ i ] ] == 'S' ) {//回溯 
					maze [ x ] [ y ] = '1';//此路不通 
					x += dx [ i ];//x改变 
					y += dy [ i ];//y改变 
					tof = true;//记录已经走过 
					ans --;//步数-1 
					break;//跳出节省时间 
				}
			}
		}
		if ( ! tof ) {//如果再也走不动 
			printf ( "I'm stuck!\n" );//无解 
			return 0;
		}
	}
	for ( int i = 0; i <= ans; i ++ ) {//如果跳出循环则一定有解 
		printf ( "%d %d\n", lj [ i ] [ 0 ], lj [ i ] [ 1 ] );
	}
	printf ( "%d\n", ans );//最后输出总步数 
//	fclose ( stdin );
//	fclose ( stdout );
	return 0;
}
