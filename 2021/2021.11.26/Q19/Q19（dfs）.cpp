/*
1. 从 1~N 中选取 7 个合数，且"最多经过 6 层 "，那么可以得知，我们要找的是 "由 2 个数相乘得到的数字 "的组合。
这样的话，乘法运算中的这 2 个数就会成为公约数。

2. 举个例子，选出 a~h 这些数, 当这 7 个数字分别是以下的形式时，经过最多 6 层就能与其他所有数产生联系。
a × b, b × c, c × d, d × e, e × f, f × g, g ×h
※这里 a~h 这些数字必须 "互质"。

3. 更进一步考虑，把第 1 个数字设置成 "平方数 "（即4），也就是说变成下面这样的组合更好:
　　a × a, a × b, b × c, c × d, d × e, e × f, f × g
末尾如果同样设置成平方数就会变得更小，也就是变成下面这样的组合:
　　a × a, a × b, b × c, c × d, d × e, e × f, f × f
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int primes[6] = {2, 3, 5, 7, 11, 13}; //用 6 个质数充当a~f
int min_friends[7];
int MIN = 13 * 13, cnt = 0; //把最小数字初始化成最大质数的平方
bool book[6];
int a[3];
void dfs(int step, int k); //按顺序从 6 个质数中选取 2 个数字作乘法，并更新组合计算最小值 

int main(){
	
	memset(book, false, sizeof(book));
	dfs(1, 0);
	
	cout << MIN << endl;	
	for(int i = 0; i < 7; i++)
		cout << min_friends[i] << " ";	
	
	return 0;
}

void dfs(int step, int k){
	if(step == 3){
		int friends[7];		
		int t[7], cnt = 0;
		for(int i = 0; i < 6; i++){
			if(!book[i]) t[cnt++] = primes[i];
		}	
		sort (t, t + 4);
		
		friends[0] = a[1] * a[1]; 		
		friends[6] = a[2] * a[2];
		do{
			friends[1] = a[1] * t[0];
			friends[2] = t[0] * t[1];
			friends[3] = t[1] * t[2];
			friends[4] = t[2] * t[3];	
			friends[5] = t[3] * a[2];	
			/*
			for(int i = 0; i < 7; i++){
				cout << friends[i] << " " ;
			}	
			cout << endl;
			*/
			int MAX = friends[0];
		
			for(int i = 1; i < 7; i++){
				if(MAX < friends[i]) MAX = friends[i];
			}	
			//cout << MAX << endl;	
			
			if(MIN > MAX){		
				MIN = MAX;
				for(int i = 0; i < 7; i++)
					min_friends[i] = friends[i];
			}			
		}while ( next_permutation(t, t + 4) );		
	}
	for(int i = k; i < 6; i++){
		if(!book[i]){
			a[step] = primes[i];
			book[i] = true;
			dfs(step + 1, i + 1);
			book[i] = false;
		}
	}
	return;
}
