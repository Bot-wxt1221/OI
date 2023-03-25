#include<cstdio>
#include<queue>
#include<set>
#define int unsigned long long
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE unsigned long long
#define OUTPUT_DATA_TYPE unsigned long long
std::set<int>a;
std::priority_queue<int>b;
INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("uglynumber.in", "r", stdin);
	freopen("uglynumber.out", "w", stdout);
	#endif
    int n=read();
    b.push(-1);
    for(int i=1;i<n;i++){
        int temp=-b.top();
        b.pop();
        if(a.find(temp*2)==a.end()){
            a.insert(temp*2);
            b.push(-temp*2);
        }
        if(a.find(temp*3)==a.end()){
            a.insert(temp*3);
            b.push(-temp*3);
        }
        if(a.find(temp*5)==a.end()){
            a.insert(temp*5);
            b.push(-temp*5);
        }
    }
    print(-b.top());
	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}