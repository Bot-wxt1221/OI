#include <cstdio>
#include <string>
#include <list>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("Doubly_Linked_List.in", "r", stdin);
	freopen("Doubly_Linked_List.out", "w", stdout);
	
	string str;
	list<int> data;
	list<int>::iterator it, l;
	int n, x;
	cin >> n;
	while(n--) {
		cin >> str;
		if(str == "insert")	{
			cin >> x;
			data.push_front(x);
		}
		else if(str == "delete") {
			cin >> x;
			for(it = data.begin(), l = data.end(); it != l; ++it) {
				if(*it == x) {
					data.erase(it);
					break;
				}
			}
		}
		else if(str == "deleteFirst") data.pop_front();
		else data.pop_back();
	}
	for(it = data.begin(), l = --data.end(); it != l; ++it) cout << *it << " ";
	cout << *it << endl;
	fclose(stdin);
	fclose(stdout);
  
  return 0;
}
