#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int cnt = 0;
	for(int coin_500 = 0; coin_500 <= 2; coin_500++)
		for(int coin_100 = 0; coin_100 <= 10; coin_100++)
			for(int coin_50 = 0; coin_50 <= 15; coin_50++)
				for(int coin_10 = 0; coin_10 <= 15; coin_10++)
				{
					if(coin_500 + coin_100 + coin_50 + coin_10 <= 15)
						if(500 * coin_500 + 100 * coin_100 + 50 * coin_50 + 10 * coin_10 == 1000)
						{
							cout << coin_500 << "+" << coin_100 << "+" << coin_50 << "+" << coin_10 << "=" << coin_500 + coin_100 + coin_50 + coin_10 << endl;
							cnt++;
						}						
				}
	cout << cnt;
}
