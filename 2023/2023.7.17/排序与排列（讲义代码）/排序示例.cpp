#include<bits/stdc++.h>
using namespace std;
bool my_less(int i, int j)      {
	return (i < j);   //自定义小于
}
bool my_greater(int i, int j)  {
	return (i > j);   //自定义大于
}
int main () {
	vector<int> a = {3,7,2,5,6,8,5,4};
	sort(a.begin(),a.begin()+4);    //对前4个排序，输出2 3 5 7 6 8 5 4
	//sort(a.begin(),a.end());        //从小到大排序， 输出2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),less<int>());    //输出2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),my_less); 	       //自定义排序，输出 2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),greater<int>()); //从大到小排序，输出 8 7 6 5 5 4 3 2
	//sort(a.begin(),a.end(),my_greater);     // 输出 8 7 6 5 5 4 3 2
	for(int i=0; i<a.size(); i++)   cout<<a[i]<< " ";      //输出
	return 0;
}

