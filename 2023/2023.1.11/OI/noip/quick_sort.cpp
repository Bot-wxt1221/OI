#include<cstdio>
#include<iostream>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

struct node{
    int data,index;
    char c;
    bool operator <= (const node another) const{
        return data<=another.data;
    }
};

node arr[100010];

int partition(int l,int r){
    register int i,j;
    node key=arr[r-1];
    for(i=l,j=l-1;i<r-1;++i){
        if(arr[i]<=key){
            std::swap(arr[i],arr[++j]);
        }
    }
    std::swap(arr[r-1],arr[j+1]);
    return j+1;
}

void quickly_sort(int l,int r){
    if(l+1<r){
        int mid=partition(l,r);
        quickly_sort(l,mid);
        quickly_sort(mid,r);
    }
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("quick_sort.in", "r", stdin);
	freopen("quick_sort.out", "w", stdout);
	#endif

    register int i;
    register char flag=0;
    int n=read();
    for(i=0;i<n;++i){
        std::cin>>arr[i].c;
        arr[i].data=read(),arr[i].index=i;
    }
    quickly_sort(0,n);
    for(i=0;i<n;++i)
        if(i&&arr[i].data==arr[i-1].data&&arr[i].index<arr[i-1].index) flag=1;

    printf("%s\n",flag?"Not stable":"Stable");

    for(i=0;i<n;++i){
        putchar(arr[i].c);
        putchar(' ');
        print(arr[i].data);
        putchar('\n');
    }

    return 0;
}