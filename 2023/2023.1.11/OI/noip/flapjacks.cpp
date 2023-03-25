#include<cstdio>
#include<algorithm>
#include<sstream>
// #define ONLINE_JUDGE
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("flapjacks.in", "r", stdin);
	freopen("flapjacks.out", "w", stdout);
	#endif

     int n,i,pos,pos2,max,tot;
    char temp;
    temp=0;
    
    while(temp!=EOF){
        std::stringstream ss;
        temp=getchar();
        while(temp!='\n'&&temp!=EOF) ss<<temp,temp=getchar();
        n=1;
        int arr[40]={0},sorted[40]={0};
        while(!ss.eof()){
        	ss>>arr[n++];
        	if(!arr[n-1]) n--;
		}
        for(i=1;i<n;++i) sorted[i]=arr[i];
        if(n==1) continue;
        for(i=1;i<n;++i) printf("%d ",arr[i]);
        putchar('\n');
        std::sort(sorted+1,sorted+n);
        tot=n;
        while(n>2){
            pos=max=-1;
            for(i=1;i<n;++i)
                if(max<arr[i]){
                    pos=i;
                    max=arr[i];
                }
            // if(std::is_sorted(arr+1,arr+tot)) break;
            pos2=n-1;
            if(pos!=pos2){
            if(pos!=1) std::reverse(arr+1,arr+pos+1),printf("%d ",tot-pos);
            if(pos2!=1) std::reverse(arr+1,arr+pos2+1),printf("%d ",tot-pos2);}
            --n;
        }
        printf("0\n");
    }

	#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}
