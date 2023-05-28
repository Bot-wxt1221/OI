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
	sort(a, a + n);//按照first排序 
	multiset<int> s;//维护所有人的结束时间
	int z = 0;
	//如果能接（小于等于开始时间）的最晚的人 
	//upper_bound找到大于等于最早的 
	//--upper_bound 就是小于等于最晚的 
	for(int i = 0; i < n; i++){
		if(s.size() > 0 && *s.begin() <= a[i].second){
			s.erase(--s.upper_bound(a[i].second));
			//--s.upper_bound(a[i].second); 
			s.insert(a[i].first); 
		} 
		//如果接不了此任务，新开一个人 
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
样例输入1： 
2
1 3
2 4
样例输出1： 
2

样例输入2：
2
1 3
3 5
样例输出2： 
1

样例输入3： 
2
1 3
2 2
样例输出3： 
2

样例输入4：
4
1 2
2 2
2 2
2 3
样例输出4： 
1
*/
