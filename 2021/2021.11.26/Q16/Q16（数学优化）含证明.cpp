/*
如果把正方形的边长设为c，那么正方形的面积就是c^2。因为周长
相等，所以其中一个长方形的长和宽可以表示如下:
c - x, c + x ( 将正方形边长增减 x )
那么这个长方形的面积就是(c - x)(c + x)，也就是 c^2 - x^2。
剩下的长方形面积则是 c^2 - (c^2 - x^2) = x^2，也就是“平方数”。
同理可知，第一个长方形的面积也一定是平方数。总结一下就是，
这些四边形的面积满足等式 a^2 + b^2 = c^2。也就是说，只需要求
满足勾股定理的整数a, b, c 的组合就可以了。

因为 "同比整数倍的结果看作同一种解法 "，因此 a 和 b的最大公约数应该为 1。
*/
#include <iostream>
#include <cstdio>
using namespace std;
int GCD(int a, int b);

int main(){
	int LEN = 500, cnt = 0;
    for(int c = 1; c <= LEN / 4; c++){
    	for(int a = 1; a < c; a ++){
    		for(int b = 1; b < c; b++){
    			if(a * a + b * b == c * c){
    				if(GCD(a, b) == 1) cnt++;
    			}
    		}
    	}
    }
	cout << cnt / 2;  //如果长和宽互换也算不同的长方形，则是 cnt 种， 如果前两根绳子互换也算不同的长方形，则是 2*cnt 种 
	
	return 0;
} 

int GCD(int a, int b){
	int t = a % b;
	while(t != 0){		
		a = b;
		b = t;
		t = a % b;
	}
	return b;
}
