#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    node *next,*pre;
    int data;
    node(){
        next=pre=NULL;
        data=0;
        return;
    }

    node(int in){
        next=NULL;
        data=in;
        return;
    }
};

int main(){
	#ifdef file
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	#endif

    node *now,*last,*head,*temp;
    last=head=new node(1);
    register int i;
    int n=read();
    int m=read();
    for(i=2;i<=n;++i){
        temp=new node(i);
        last->next=temp;
        temp->pre=last;
        last=temp;
    }

    last->next=head;
    head->pre=last;

    now=last;
    while(--n){
        for(i=1;i<m;++i)
            now=now->next;
        temp=now->next;
        now->next=now->next->next;
        now->next->pre=now;
        printf("%d ",temp->data);
        delete(temp);
    }

    printf("%d",now->data);


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}