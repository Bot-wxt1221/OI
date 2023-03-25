#include<cstdio>
#include<iostream>
#include<algorithm>
#define file
#define int long long
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    int pos,index;
    char dire;
    bool operator < (const node another) const{
        return pos<another.pos;
    }
}arr[10010],bak[10010];

inline bool cmp1(node a,node b){
	return a.pos<b.pos;
}

inline bool cmp2(node a,node b){
	return a.index<b.index;
}

signed main(){
	#ifdef file
	freopen("antII.in", "r", stdin);
	freopen("antII.out", "w", stdout);
	#endif

    register int i,j,pos;
    register char dire;
    int L=read();
    int t=read();
    int n=read();
    for(i=0;i<n;++i){
        pos=read();
        std::cin>>dire;
        dire=(dire=='L'?-1:1);
        bak[i].pos=pos;
        bak[i].index=i;
        pos=pos+(dire*t);
        arr[i].pos=pos;
        arr[i].dire=dire;
        arr[i].index=i;

    }

    std::sort(arr,arr+n,cmp1);
    std::sort(bak,bak+n,cmp1);

    for(i=0;i<n;++i){
    	arr[i].index=bak[i].index;
        if(0<arr[i].pos&&arr[i].pos<=L){
            if(arr[i].pos==arr[i+1].pos){
                arr[i].dire=arr[i+1].dire=0;
            }
        }
    }
    
    std::sort(arr,arr+n,cmp2);
    
    for(i=0;i<n;++i){
    	if(0<=arr[i].pos&&arr[i].pos<=L){
    		print(arr[i].pos);
    		putchar(' ');
    		puts(arr[i].dire==-1?"L":(arr[i].dire==1?"R":"Turning"));
		}else{
			puts("Fell off");
		}
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
