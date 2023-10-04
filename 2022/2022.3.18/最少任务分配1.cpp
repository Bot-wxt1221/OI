#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int nmax = 200000 + 10; 
pair<int,int> a[nmax];
 
int main() {
	priority_queue<int>q;
	int n; //任务数 	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	} 
    sort(a, a + n);//按照first排序
    //加入相反数实现小根堆的效果，就是根是绝对值越小的 
    int z = 0;
	for(int i = 0; i < n; i++){
		//遇到一个新任务，试图让q.top()去接
		//如果能接，则更新 
		if(q.size() > 0 && -q.top() <= a[i].first){
			q.pop(); //弹出q.top();
			q.push(-a[i].second);
		}
		//如果不能接，则新开一个人去接
		else{
			q.push(-a[i].second);
			z++; 
		} 
	} 
	cout << z << endl;

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
