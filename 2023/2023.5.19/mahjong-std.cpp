#include <cstdio>
#include <cstring>
using namespace std;

const char* mahjong[] = {
	"1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
	"1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
	"DONG", "NAN", "XI", "BEI",
	"ZHONG", "FA", "BAI"
};

int convert(char *s) {
	for(int i = 0; i < 34; i++) {
		if(strcmp(mahjong[i], s) == 0) return i;
	}
	return -1;
}

int c[34];
bool search(int dep) {
	for(int i = 0; i < 34; i++) {
		if(c[i] >= 3) {  //刻子：三张相同的牌 
			if(dep == 3) return true;
			c[i] -= 3;
			if(search(dep + 1)) return true; 
			c[i] += 3;
		}
	}
	
	for(int i = 0; i <= 24; i++) {
		if(i % 9 <= 6 && c[i] >= 1 && c[i + 1] >= 1 && c[i + 2] >= 1) {  //顺子：三张同花色相连的牌 
			if(dep == 3) return true;
			c[i]--; c[i + 1]--; c[i + 2]--;
			if(search(dep + 1)) return true;
			c[i]++; c[i + 1]++; c[i + 2]++; 
		}
	}
	return false;
}

bool check() {
	for(int i = 0; i < 34; i++) {
		if(c[i] >= 2) { //将牌：一对相同的牌 
			c[i] -= 2;
			if(search(0)) return true;
			c[i] += 2;
		}
	}
	return false;
}

int main() {
//	freopen("mahjong.in", "r", stdin);
//	freopen("mahjong.out", "w", stdout);
	int caseno = 0, mj[15];
	bool ok;
	char s[100];
	
	while(scanf("%s", s) == 1) {
		if(s[0] == '0') break;
		printf("Case %d:", ++caseno);
		
		mj[0] = convert(s);
		for(int i = 1; i < 13; i++) {
			scanf("%s", s);
			mj[i] = convert(s);
		}
		
		ok = false;
		for(int i = 0; i < 34; i++) {
			memset(c, 0, sizeof(c));
			for(int j = 0; j < 13; j++) {
				c[mj[j]]++;
			}
			if(c[i] >= 4) continue;  //每种牌最多只有 4 张
			c[i]++;  //假设拥有这张牌
			if(check()) {  //如果 “和 ”了 
				ok = true;
				printf(" %s", mahjong[i]);
			} 
			c[i]--;
		}
		
		if(!ok) printf(" Not ready");
		printf("\n");
	}
	
	return 0;
}

/*
Sample Input
1S 1S 2S 2S 2S 3S 3S 3S 7S 8S 9S FA FA
1S 2S 3S 4S 5S 6S 7S 8S 9S 1T 3T 5T 7T
0

Sample Output
Case 1: 1S 4S FA
Case 2: Not ready
*/


















