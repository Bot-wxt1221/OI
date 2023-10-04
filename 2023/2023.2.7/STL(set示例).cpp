#include <iostream>
#include <set>
using namespace std;

void print(set<int> S) {
	cout << S.size() << ":";
	for(set<int>::iterator it = S.begin(); it != S.end(); it++) {
		cout << " " << (*it);
	}
	cout << endl;
} 

int main() {
	set<int> S;
	S.insert(8);
	S.insert(1);
	S.insert(7);
	S.insert(4);
	S.insert(8);
	S.insert(4);
	
	print(S);
	
	S.erase(7);	
	print(S);
	
	S.insert(2);	
	print(S);
	
	if( S.find(10) == S.end() ) cout << "not found." << endl;
	
	return  0;
}
