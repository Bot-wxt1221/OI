#include <cstdio>
#define NIL (-1)
using namespace std;

struct node {
    int parent, left, right;
    int key;
} tree[500001];

int treesize, root = NIL;

void pre(int id) {
    if(id == -1)   return;
    printf(" %d", tree[id].key);
    if(tree[id].left >= 0)   pre(tree[id].left);
    if(tree[id].right >= 0)  pre(tree[id].right);
}

void in(int id) {
    if(id == -1)   return;
    if(tree[id].left >= 0)   in(tree[id].left);
    printf(" %d",tree[id].key);
    if(tree[id].right >= 0)  in(tree[id].right);    
}

void insert(int key) {
    int y = NIL, x = root;
    while(x != NIL) {
        y = x;
        if(key < tree[x].key)  x = tree[x].left;
        else  x = tree[x].right;
    }
    tree[treesize].parent = y;

    if(y == NIL)  root = treesize;
    else if(key < tree[y].key)  tree[y].left = treesize;
    else  tree[y].right = treesize;
    tree[treesize].left = NIL;  
	tree[treesize].right = NIL;
	tree[treesize].key = key;
    treesize++;        
}

bool find(int key) {
    int x = root;

    while(x != NIL) {
        if(key < tree[x].key)   x = tree[x].left;
        else if(key > tree[x].key)  x = tree[x].right;
        else  return true;
    }
    return false;
}

int getnext(int start) {
	int x = tree[start].right;
	while(tree[x].left != NIL)
		x = tree[x].left;
	return tree[x].key;
}

void dlt(int root,int key) {
    int x = root;
    while(x != NIL) {
		if(key < tree[x].key)   x = tree[x].left;
		else if(key > tree[x].key)   x = tree[x].right;
		else {
			if(tree[x].left != NIL && tree[x].right != NIL) {
			    int nextkey = getnext(x);
			    dlt(x, nextkey);
			    tree[x].key = nextkey;
			}else if(tree[x].left == NIL && tree[x].right == NIL) {
			    if(tree[tree[x].parent].left == x)    tree[tree[x].parent].left = NIL;
			    else  tree[tree[x].parent].right = NIL;
			}else {
			    int y = tree[x].left != NIL ? tree[x].left : tree[x].right;
			    if(tree[tree[x].parent].left == x)    tree[tree[x].parent].left = y;
			    else  tree[tree[x].parent].right = y;
			    tree[y].parent = tree[x].parent;
			}
		    break;
		}
    }
}


int main(void) {
    int n;
    freopen("delete_bst.in", "r", stdin);
    freopen("delete_bst.out", "w", stdout);
    scanf("%d",&n);

    for(int i = 0;i < n;i++) {
        char s[20]; 
        int key;
        scanf("%s",s);

        if(s[0] == 'i') {           
            scanf("%d", &key);
            insert(key);
        }else if(s[0] == 'f') {           
            scanf("%d", &key);
            if(find(key))   printf("yes\n");
            else  printf("no\n");
        }else if(s[0] == 'd') {            
            scanf("%d", &key);
            dlt(root,key);
        }
        else {
            in(root);
            printf("\n");
            pre(root);
            printf("\n");
        }
    }
		
    return 0;
}

