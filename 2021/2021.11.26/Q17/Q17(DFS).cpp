/*
在满足条件的排列方法中，“每次添加一人，并保证女生不会连续
排列”这种方法相对简单。那么，当 n人排列时，如果最右边是男生，
则“加一个男生或者一个女生”；如果最右边是女生，则“只能加一个
男生”。
*/
#include <iostream>
#include <cstdio>
using namespace std;

string boy = "B", girl = "G";
int N;
long long int add(string seq);

int main(){
	cin >> N;
	cout << add(boy) + add(girl);
	return 0;
}

long long int add(string seq){
	if(seq.size() == N){ //到达排列人数上限，终止递归
		cout << seq << endl;
		return 1LL;  
	}
	//未满人数上限时，加男生，当右边为男生时加女生
	long long int cnt = 0;
	cnt += add(seq + boy);
	if(seq[seq.size() - 1] == 'B') cnt += add(seq + girl); 
	return cnt;
}
