#include<cstdio>
#include<cstring>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

#define TRIE_TYPE char
const int TRIE_DATA_SIZE=128;const int TRIE_TREE_SIZE=120000;struct TRIE{int next[TRIE_TREE_SIZE][TRIE_DATA_SIZE],nown;bool book[TRIE_TREE_SIZE];void insert(char*s,int len){int pos=0;for(register int i=0;i<len;++i)pos=next[pos][s[i]]?next[pos][s[i]]:(next[pos][s[i]]=++nown);book[pos]=1;return;}bool find(char*s,int len){int pos=0;for(register int i=0;i<len;++i){if(!next[pos][s[i]])return 0;pos=next[pos][s[i]];}return book[pos];}void del(char*s){int pos=0;int len=strlen(s);for(register int i=0;i<len;++i){if(!next[pos][s[i]])return;pos=next[pos][s[i]];}book[pos]=0;return;}void clear(){memset(this,0,sizeof(TRIE));;return;}};
TRIE map;

char s[200];

int main(){
	#ifdef file
	freopen("dictionary.in", "r", stdin);
	freopen("dictionary.out", "w", stdout);
	#endif

    register int i,j,len;
    register unsigned long long ans;
    int n=read();
    for(i=0;i<n;++i){
        scanf("%s",s);

        if(s[0]=='i'){
            scanf("%s",s);
            len=strlen(s);
            if(!map.find(s,len))map.insert(s,len);
        }else{
            scanf("%s",s);
            len=strlen(s);
            puts(map.find(s,len)?"yes":"no");
        }
    }


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}