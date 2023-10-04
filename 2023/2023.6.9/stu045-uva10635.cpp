
#include<cstdio>
#include<bitset>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

//bit templates begining------------
#include<cstring>
#define BIT_DATA_TYPE int
const int BIT_SIZE=260*260;
struct BIT{
    BIT_DATA_TYPE tree[BIT_SIZE];
    int size;

    BIT_DATA_TYPE presum(int pos){
        BIT_DATA_TYPE sum=0;
        while(pos){
            sum=std::max(tree[pos],sum);
            pos-=lowbit(pos);
        }
        return sum;
    }

    void add(BIT_DATA_TYPE data,int pos){
        while(pos<=size){
            tree[pos]=std::max(data,tree[pos]);
            pos+=lowbit(pos);
        }
    }

    BIT_DATA_TYPE lowbit(BIT_DATA_TYPE x){
        return x&-x;
    }

    void clear(){
        memset(this,0,sizeof(BIT));
        return;
    }
}bit;
//bit templates end------------

int a[260*260],b[260*260],pa[260*260],posb[260*260],pos[260*260];
std::bitset<260*260> booka,bookb,book;

void clear(int n){
    bit.clear();
    register int i;
    for(i=1;i<=n*n;++i) book[i]=booka[i]=bookb[i]=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(a));
    memset(pa,0,sizeof(a));
    memset(posb,0,sizeof(a));
    memset(pos,0,sizeof(a));
    return;
}

/*
*---树状数字版的LIS做法---
*设 f[i] 表示以元素值为 i 结尾的lis。
*1.取出答案: 依次考虑每一个 arr[i] 结尾的答案，显然就是 nowans = max(f[j])+1 (1<=j<=i or j<i 注意这个地方取决于是否严格) 。
            时间复杂度: O(maxnum) (force 暴力)
            优化: 观察到实际上在求前缀最大值，树状数组是处理前缀有结合律问题的好东西，可以用树状数组优化到 O(log(maxnum))。
*2.更新数组: 显然需把 nowans 放进去，则 f[arr[i]] <-- max(nowans,f[arr[i]])
*时间复杂度 O(n*log(maxnum)) 空间复杂度 O(n+maxnum)
*---扩展---
*实际上到这一步完全可以通过此题，但是观察到时/空复杂度取决于值域，若值域更大，则会爆空间
*考虑进行离散化压缩值域，注意到只需要判断两个元素的大小关系，那我们按照大小关系重新分配一个值，把值域压到 O(n) 则可以完成。
*
*/

int LIS(int n){
    register int i,t,res=0;
    bit.size=n;
    for(i=0;i<n;++i){
        t=bit.presum(pos[i])+1;
        bit.add(t,pos[i]);
        res=std::max(res,t);
    }
    return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    register int i,n,p,q,lp,t,_tt=0;
    int T=read();
    while(T--){
        n=read();
        p=read()+1;
        q=read()+1;

        //clear
        clear(n);

        //read & get common numbers
        for(i=0;i<p;++i) a[i]=read(),booka[a[i]]=1;
        for(i=0;i<q;++i) b[i]=read(),bookb[b[i]]=1;
        for(i=1;i<=n*n;++i) book[i]=booka[i]&&bookb[i];
        
        //get pa (in common numbers)
        for(i=lp=0;i<p;++i)
            if(book[a[i]]) pa[lp++]=a[i];
        //get posb (in common numbers)
        for(i=lp=0;i<q;++i)
            if(book[b[i]]) posb[b[i]]=lp++;

        n=lp;

        //get mapping pos
        for(i=0;i<n;++i)
            pos[i]=posb[pa[i]]+1;

        printf("Case %d: ",++_tt);
        print(LIS(n));putchar('\n');
    }


	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}