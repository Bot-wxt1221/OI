/*
运用了比较多的循环，可能不是那么快...
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
	while ( cin >> x [ i ] ) {//输入 
		if ( maxn <= x [ i ] ) {//判断是否较高 
			maxn = x [ i ];//赋值 
			ans += cnt;//将cnt纳入ans 
			j = i;//为后面重新搜索做准备 
			cnt = 0;//cnt清空 
		}else{//否则 
			cnt += maxn - x [ i ];//加入按最高高度可以接的水 
		}
		i ++;//判断总个数 
	}
	while ( cnt != 0 ) {//如果后面还有可以搜索的空间 
		maxn --;//最高高度降低 
		cnt = 0;//重新搜索 
		for ( int k = j + 1; k < i; k ++ ) {//几乎和上次一样 
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
	printf ( "%d\n", ans );//输出 
	fclose ( stdin );
	fclose ( stdout );
	return 0;
}
