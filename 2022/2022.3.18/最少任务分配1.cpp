#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int nmax = 200000 + 10; 
pair<int,int> a[nmax];
 
int main() {
	priority_queue<int>q;
	int n; //������ 	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	} 
    sort(a, a + n);//����first����
    //�����෴��ʵ��С���ѵ�Ч�������Ǹ��Ǿ���ֵԽС�� 
    int z = 0;
	for(int i = 0; i < n; i++){
		//����һ����������ͼ��q.top()ȥ��
		//����ܽӣ������ 
		if(q.size() > 0 && -q.top() <= a[i].first){
			q.pop(); //����q.top();
			q.push(-a[i].second);
		}
		//������ܽӣ����¿�һ����ȥ��
		else{
			q.push(-a[i].second);
			z++; 
		} 
	} 
	cout << z << endl;

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
