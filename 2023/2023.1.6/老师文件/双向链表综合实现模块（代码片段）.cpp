// 双向链表
struct Node {
	int value; // data
	Node *prev, *next; // pointers
};
Node *head, *tail;

void initialize() { // create an empty list
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}

void insert(Node *p, int value) { // insert data after p
	q = new Node();
	q->value = value;
	p->next->prev = q; q->next = p->next;
	p->next = q; q->prev = p;
}

void remove(Node *p) { // remove p
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
}

void recycle() { // release memory
	while (head != tail) {
		head = head->next;
		delete head->prev;
	}
	delete tail;
}

//---------------------------------------------------------------------

// 数组模拟链表
struct Node {
	int value;
	int prev, next;
} node[SIZE];
int head, tail, tot;

int initialize() {
	tot = 2;
	head = 1, tail = 2;
	node[head].next = tail;
	node[tail].prev = head;
}

int insert(int p, int value) {
	q = ++tot;
	node[q].value = value;
	node[node[p].next].prev = q;
	node[q].next = node[p].next;
	node[p].next = q; node[q].prev = p;
}

void remove(int p) {
	node[node[p].prev].next = node[p].next;
	node[node[p].next].prev = node[p].prev;
}


