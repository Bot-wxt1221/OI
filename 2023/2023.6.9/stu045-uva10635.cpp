
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
*---��״���ְ��LIS����---
*�� f[i] ��ʾ��Ԫ��ֵΪ i ��β��lis��
*1.ȡ����: ���ο���ÿһ�� arr[i] ��β�Ĵ𰸣���Ȼ���� nowans = max(f[j])+1 (1<=j<=i or j<i ע������ط�ȡ�����Ƿ��ϸ�) ��
            ʱ�临�Ӷ�: O(maxnum) (force ����)
            �Ż�: �۲쵽ʵ��������ǰ׺���ֵ����״�����Ǵ���ǰ׺�н��������ĺö�������������״�����Ż��� O(log(maxnum))��
*2.��������: ��Ȼ��� nowans �Ž�ȥ���� f[arr[i]] <-- max(nowans,f[arr[i]])
*ʱ�临�Ӷ� O(n*log(maxnum)) �ռ临�Ӷ� O(n+maxnum)
*---��չ---
*ʵ���ϵ���һ����ȫ����ͨ�����⣬���ǹ۲쵽ʱ/�ո��Ӷ�ȡ����ֵ����ֵ�������ᱬ�ռ�
*���ǽ�����ɢ��ѹ��ֵ��ע�⵽ֻ��Ҫ�ж�����Ԫ�صĴ�С��ϵ�������ǰ��մ�С��ϵ���·���һ��ֵ����ֵ��ѹ�� O(n) �������ɡ�
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