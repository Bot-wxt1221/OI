#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
	char name[100];
	int time;
};

#define QUEUE_DATA_TYPE node
const int QUEUE_SIZE = 100010;
struct QUEUE{
	QUEUE_DATA_TYPE q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	void push(QUEUE_DATA_TYPE in){
		tail=tail+1<QUEUE_SIZE?tail+1:0;
		q[tail]=in;
		++num;
		return;
	}

	void pop(){
		head=head+1<QUEUE_SIZE?head+1:0;
		--num;
		return;
	}

	void push_front(QUEUE_DATA_TYPE in){
		head=(~(head-1))?QUEUE_SIZE-1:head-1;
		q[head]=in;
		++num;
		return;
	}

	void pop_back(){
		tail=(~(tail-1))?QUEUE_SIZE-1:tail-1;
		--num;
		return;
	}

	QUEUE_DATA_TYPE front(){
		return q[head];
	}

	QUEUE_DATA_TYPE back(){
		return q[tail];
	}

	void clear(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	bool empty(){
		return !num;
	}

	int size(){
		return num;
	}

	QUEUE_DATA_TYPE read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
}Q;

int main(){
	#ifdef file
	freopen("schedule.in", "r", stdin);
	freopen("schedule.out", "w", stdout);
	#endif
	
	register int i,cnttime=0;;
	register node now;
	int n=read();
	int q=read();
	
	for(i=0;i<n;++i){
		scanf("%s",now.name);
		now.time=read();
		Q.push(now);
	}
	while(!Q.empty()){
		now=Q.front();
		Q.pop();
		if(now.time>q){
			now.time-=q;
			Q.push(now);
			cnttime+=q;
		}else{
			cnttime+=now.time;
			printf("%s ",now.name);
			print(cnttime);
			putchar('\n');
		}
	}
	
	

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

