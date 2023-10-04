#include<cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
class gao{
    public:
        short temp[100];
        int number;
}dp[55][55],num[55][55];
char temp[55];
gao operator + (gao a,gao b) {
    if(a.number>b.number){
        std::swap(a,b);
    }
    for(int i=1;i<=a.number;i++){
        b.temp[i]+=a.temp[i];
    }
    for(int i=1;i<=b.number;i++){
        if(b.temp[i]>=10){
            b.temp[i]-=10;
            b.temp[i+1]++;
        }
    }
    while(b.temp[b.number+1]){
        b.number++;
    }
    return b;
}
bool operator < (gao a,gao b){
    if(a.number>b.number){
        return 0;
    }
    if(a.number<b.number){
        return 1;
    }
    for(int i=b.number;i>=1;i--){
        if(b.temp[i]<a.temp[i]){
            return 0;
        }
        if(a.temp[i]<b.temp[i]){
            return 1;
        }
    }
    return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
	#endif
    int m;
    while(scanf("%d",&m)!=EOF){
        scanf("%s",temp+1);
        int siz=strlen(temp+1);
        std::reverse(temp+1,temp+siz+1);
        for(int i=1;i<=siz;i++){
            for(int j=i;j<=siz;j++){
                num[i][j].number=j-i+1;
                for(int kk=i;kk<=j;kk++){
                    num[i][j].temp[kk-i+1]=temp[kk]-'0';
                }
            }
        }
        for(int i=1;i<=siz;i++){
            dp[0][i]=num[1][i];
        }
        gao temp;
        temp.number=99;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=siz;j++){
                dp[i][j].number=99;
                if(i+1>j){
                    continue ;
                }
                for(int k=1;k<=j;k++){
                    dp[i][j]=std::min(dp[i][j],dp[i-1][k]+num[k+1][j]);
                }
            }
        }
        for(int i=dp[m][siz].number;i>=1;i--){
            putchar(dp[m][siz].temp[i]+'0');
        }
        putchar('\n');
    }
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
