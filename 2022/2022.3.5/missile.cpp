/*
̰������ÿ������ 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
bool vised[1005];
int h[1005];
int main(){
	freopen("missile.in","r",stdin);
	freopen("missile.out","w",stdout);
	int n=1;
	for(;!cin.eof();n++){
		cin>>h[n];//���� 
	}
	int used=0,have=0;
	while(have<n){//����ÿ����Ҫ���� 
		used++;
		int free=60005;
		bool havse=0;
		for(int i=1;i<=n;i++){//ѡʣ�µĵ�����һ������ 
			if(!vised[i]){
				if(h[i]<=free){ 
					have++;//�������� 
					vised[i]=1;
					free=h[i];
				}
			}
		}
	}
	cout<<used;
	return 0;
}
