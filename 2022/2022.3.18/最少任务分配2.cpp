#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
const int nmax = 200000 + 20;
pair<int,int> a[nmax];
 
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);//����first���� 
	multiset<int> s;//ά�������˵Ľ���ʱ��
	int z = 0;
	//����ܽӣ�С�ڵ��ڿ�ʼʱ�䣩��������� 
	//upper_bound�ҵ����ڵ�������� 
	//--upper_bound ����С�ڵ�������� 
	for(int i = 0; i < n; i++){
		if(s.size() > 0 && *s.begin() <= a[i].second){
			s.erase(--s.upper_bound(a[i].second));
			//--s.upper_bound(a[i].second); 
			s.insert(a[i].first); 
		} 
		//����Ӳ��˴������¿�һ���� 
		else{
			s.insert(a[i].first);
			z++;
		}
	}
	//cout<<z<<endl; 
	printf("%d\n", z);
	return 0;
}

/*
��������1�� 
2
1 3
2 4
�������1�� 
2

��������2��
2
1 3
3 5
�������2�� 
1

��������3�� 
2
1 3
2 2
�������3�� 
2

��������4��
4
1 2
2 2
2 2
2 3
�������4�� 
1
*/
