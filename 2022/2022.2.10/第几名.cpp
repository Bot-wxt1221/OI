#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	char ch[6];
	for(int a = 1; a <= 5; a++){
		for(int b = 1; b <= 5; b++){
			if(b != a){
				for(int c = 1; c <= 5; c++){
					if(c != a && c != b){
						for(int d = 1; d <= 5; d++){
							if(d != a && d != b && d != c){
								for(int e = 1; e <= 5; e++){
									if(e != a && e != b && e != c && e != d){
										if(a == 1 || b == 2 || c == 3 || d == 4 || e == 5) continue; //ABCDE没猜对一个人的名次
										if( (b == a + 1) || (c == b + 1) || (d == c + 1) || (e == d + 1) ) continue; //ABCDE没猜对一对相邻名次
										if( ((a == 2) + (b == 5) + (c == 4) + (d == 1) + (e == 3)) != 2 ) continue; //DAECB猜对了两个人的名次										
										if( ((a == d + 1) + (e == a + 1) + (c == e + 1) + (b == c + 1)) != 2 ) continue; //DAECB猜对了两对相邻人名次
										ch[a] = 'A'; 
										ch[b] = 'B';
										ch[c] = 'C';
										ch[d] = 'D';
										ch[e] = 'E';
										for(int i = 1; i <= 5; i++){
											cout << ch[i] << " ";
										}
										cout << endl;	
									}						
								}	
							}				
						}
					}				
				}
			}			
		}
	}
	return 0;
}



























