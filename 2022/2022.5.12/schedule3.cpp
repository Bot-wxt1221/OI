#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 100005
using namespace std;
//��������Ľṹ��
typedef struct pp{
	char name[100];
	int t;
} P;

P Q[LEN];
int head, tail;

void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
} 

P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int main(){
	int elaps = 0, c;
	int n, q;
	P u;
	freopen("schedule.in", "r", stdin);
	freopen("schedule.out", "w", stdout);
	scanf("%d %d", &n, &q);
	
	//��˳�������������������
	for (int i = 1; i <= n; i++){
		scanf("%s", Q[i].name);
		scanf("%d", &Q[i].t);
	} 
	head = 1; tail = n + 1;
	
	//ģ��
	while (head != tail){
		u = dequeue();
		c = min(q, u.t);  //ִ��ʱ��Ƭ q ������ʱ�� u.t �Ĵ���
		u.t -= c;   //����ʣ�������ʱ��
		elaps += c; //�ۼ��Ѿ�����ʱ��
		if (u.t > 0) enqueue(u);  //���������δ���������������������
		else printf("%s %d\n", u.name, elaps); 
	} 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}


