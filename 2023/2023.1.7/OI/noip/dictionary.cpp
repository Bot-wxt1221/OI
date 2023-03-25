#include<cstdio>
#include<cstring>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

#include<cstdlib>
#include<ctime>
#define HASH_MAP_DATA_TYPE unsigned long long
const int MAX_HASH_TIMES=10;
const int MAX_HASH_MOD=(11451481);
const int MIN_HASH_MOD=(5451481);
struct HASH_MAP{
    char hash_map[MAX_HASH_MOD][MAX_HASH_TIMES];
    int hash_times;
    unsigned int mod[MAX_HASH_TIMES];
    HASH_MAP(int in){
        srand(time(NULL));
        hash_times=in;
        for(register int i=0;i<hash_times;++i) mod[i]=(rand()*rand()*mod[i-1])%(MAX_HASH_MOD-MIN_HASH_MOD)+MIN_HASH_MOD,mod[i]=(mod[i]?mod[i]:1);
        return;
    }

    void insert(HASH_MAP_DATA_TYPE in){
        for(register int i=0;i<hash_times;++i) hash_map[in%mod[i]][i]=1;
        return;
    }

    bool find(HASH_MAP_DATA_TYPE in){
        for(register int i=0;i<hash_times;++i)
            if(!hash_map[in%mod[i]][i]) return false;
        return true;
    }
}map(2);

unsigned long long w[20];

char s[20];

int main(){
	#ifdef file
	freopen("dictionary.in", "r", stdin);
	freopen("dictionary.out", "w", stdout);
	#endif

    register int i,j,len;
    register unsigned long long ans;
    w[0]=rand()*rand()*rand();
    for(i=1;i<20;++i) w[i]=rand()*rand()*w[i-1]+114514;
    int n=read();
    for(i=0;i<n;++i){
        scanf("%s",s);

        if(s[0]=='i'){
            scanf("%s",s);
            len=strlen(s);
            ans=0;
            for(j=0;j<len;++j) 
            ans+=s[j]*w[j];
            map.insert(ans);
        }else{
            scanf("%s",s);
            len=strlen(s);
            ans=0;
            for(j=0;j<len;++j) 
            ans+=s[j]*w[j];
            puts(map.find(ans)?"yes":"no");
        }
    }


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}