#include<bits/stdc++.h>
using namespace std;
bool my_less(int i, int j)      {
	return (i < j);   //�Զ���С��
}
bool my_greater(int i, int j)  {
	return (i > j);   //�Զ������
}
int main () {
	vector<int> a = {3,7,2,5,6,8,5,4};
	sort(a.begin(),a.begin()+4);    //��ǰ4���������2 3 5 7 6 8 5 4
	//sort(a.begin(),a.end());        //��С�������� ���2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),less<int>());    //���2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),my_less); 	       //�Զ���������� 2 3 4 5 5 6 7 8
	//sort(a.begin(),a.end(),greater<int>()); //�Ӵ�С������� 8 7 6 5 5 4 3 2
	//sort(a.begin(),a.end(),my_greater);     // ��� 8 7 6 5 5 4 3 2
	for(int i=0; i<a.size(); i++)   cout<<a[i]<< " ";      //���
	return 0;
}

