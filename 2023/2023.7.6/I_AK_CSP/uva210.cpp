#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
inline int read();
char temp[25];
char temp2[25];
class ord{
    public:
        int type;
        int number;
        int number2=0;
        ord(int a=0,int b=0,int c=0){
            type=a;
            number=b;
            number2=c;
        }
};
class pro{
    public:
        ord order[30];
        int ornum=0;
        int now=1;
        int num=0;
        bool out=0;
        pro(int a=0,int b=0){
            num=a;
            now=1;
            ornum=b;
        }
};
std::deque<pro> wait;
std::queue<pro> block;
int val[300];
int t[10];
int main(){
        // #ifdef ONLINE_JUDGE
        // #else
        // freopen("1.in.txt","r",stdin);
        // freopen(".out","w",stdout);
        // #endif
    int T=read();
    while(T--){
        memset(val,0,sizeof(val));
        int n=read(),q;
        t[1]=read();
        t[2]=read();
        t[3]=read();
        t[4]=read();
        t[5]=read();
        q=read();
        for(int i=1;i<=n;i++){
            pro tmp(i,0);
            while(1){
            scanf("%s",temp+1);
            if(temp[1]=='p'&&temp[2]=='r'){
                scanf("%s",temp2+1);
                ord tmp2;
                tmp2.type=2;
                tmp2.number=temp2[1];
                tmp.ornum++;
                tmp.order[tmp.ornum]=tmp2;
            }else if(temp[2]=='\0'){
                scanf("%s",temp2+1);
                int d=0;
                scanf("%d",&d);
                ord tmp2;
                tmp2.type=1;
                tmp2.number=temp[1];
                tmp2.number2=d;
                tmp.ornum++;
                tmp.order[tmp.ornum]=tmp2;
            }else if(temp[1]=='l'&&temp[2]=='o'){
                ord tmp2;
                tmp2.type=3;
                tmp.ornum++;
                tmp.order[tmp.ornum]=tmp2;
            }else if(temp[1]=='u'&&temp[2]=='n'){
                ord tmp2;
                tmp2.type=4;
                tmp.ornum++;
                tmp.order[tmp.ornum]=tmp2;
            }else if(temp[1]=='e'&&temp[2]=='n'){
                ord tmp2;
                tmp2.type=5;
                tmp.ornum++;
                tmp.order[tmp.ornum]=tmp2;
		break;
            }else{
                printf("sbUVA鏁版嵁鏍煎紡閿欎簡!!!");
                return 0;
            }
}
            wait.push_back(tmp);
        }
        bool lock=0;
        while(wait.size()>0){
            pro temp=wait.front();
            wait.pop_front();
            int time=0;
            bool in=0;
            for(;temp.now<=temp.ornum&&time<q;temp.now++){
                int &i=temp.now;
                time+=t[temp.order[i].type];
                if(temp.order[i].type==2){
                    printf("%d: %d\n",temp.num,val[temp.order[i].number]);
                }else if(temp.order[i].type==1){
                    val[temp.order[i].number]=temp.order[i].number2;
                }else if(temp.order[i].type==3){
                    if(lock){
                        // temp.now++;
                        temp.out=1;
                        block.push(temp);
                        in=1;
                        break;
                    }else{
                        temp.out=0;
                        lock=1;
                    }
                }else if(temp.order[i].type==4){
                    lock=0;
if(block.size()>0){
                    wait.push_front(block.front());
                    block.pop();
}
                }
            }
            if(!in&&temp.now<=temp.ornum){
                wait.push_back(temp);
            }
        }
        if(T!=0){
        	printf("\n");
		}
    }
        return 0;
}
inline int read(){
        int x=0,f=1;char c=getchar();
        while(c<'0'||c>'9'){
                c=='-'?f=-1:1;
                c=getchar();
        }
        while(c>='0'&&c<='9'){
                x=(x<<3)+(x<<1)+(c^48);
                c=getchar();
        }
        return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
        1:
                In:

                Out:
More:

*/
