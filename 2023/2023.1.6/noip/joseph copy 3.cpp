#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    int next;
    int data;
    node(){
        next=-1;
        data=0;
        return;
    }

    node(int in){
        next=-1;
        data=in;
        return;
    }
};

node arr[10000];int tot;

int main(){
	#ifdef file
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	#endif

    int now,last,head,temp;
    last=head=tot++;
    arr[head].data=1;
    register int i;
    int n=read();
    int m=read();
    for(i=2;i<=n;++i){
        temp=tot++;
        arr[temp].data=i;
        // last->next=temp;
        arr[last].next=temp;
        last=temp;
    }

    arr[last].next=head;

    now=last;
    while(--n){
        for(i=1;i<m;++i)
            now=arr[now].next;
        temp=arr[now].next;
        arr[now].next=arr[arr[now].next].next;
        printf("%d ",arr[temp].data);
    }

    printf("%d",arr[now].data);


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}  