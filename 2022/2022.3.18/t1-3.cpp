/*
˼·2�����ȶ��У�
*/ 

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
 
int main() { 
	//freopen("t1.in", "r", stdin);
	//freopen("t1.out", "w", stdout);
	priority_queue<int,vector<int>, greater<int> >q;   //greater��С���ѣ���С�������
	//priority_queue<int,vector<int>,less<int>>q;     // less�Ǵ���ѣ� �Ӵ�С��� 
    //priority_queue<int>qĬ�ϴӴ�С����(�����)
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
