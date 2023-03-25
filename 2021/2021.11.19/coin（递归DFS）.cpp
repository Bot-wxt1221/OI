#include <cstdio>
#include <iostream>
using namespace std;

int cnt = 0;
int coins[4] = {500, 100, 50, 10};
void dfs(int value, int num, int step);

int main(){		
	dfs(1000, 15, 0);
	cout << cnt;
}

void dfs(int value, int num, int step){
 	if(step == 4){
 		if(value == 0 && num >= 0) 
 			cnt++;
 	} 	
 	else{
			for(int i = 0; i <= value / coins[step]; i++)
			{
				if(value - i * coins[step] >= 0 && num - i >= 0)
					dfs(value - i * coins[step], num - i, step + 1);
			}
 	}
}
