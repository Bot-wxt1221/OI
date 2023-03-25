/*
思路2（优先队列）
*/ 

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
 
int main() { 
	//freopen("t1.in", "r", stdin);
	//freopen("t1.out", "w", stdout);
	priority_queue<int,vector<int>, greater<int> >q;   //greater是小根堆，从小到大输出
	//priority_queue<int,vector<int>,less<int>>q;     // less是大根堆， 从大到小输出 
    //priority_queue<int>q默认从大到小排序(大根堆)
    int n;
    int x;
    while(cin >> n){
    	for(int i = 0; i < n; i++){
    		cin >> x;
    		q.push(x);
		}
		int sum = 0; 
    	while(!q.empty()){
    	//while(q.size()){
		    sum += q.top() * q.size(); //a[i]*(n-i) 
		    q.pop();
	    }
	    cout << sum << endl;
	} 

	return 0;
}
