#include "cstdio"
#include "cstring"
#include "stack"
using namespace std;
 
int n;
int m;
int thisid = -1;
int maxson;
 
typedef pair<pair<int,int>,int> pic; //deep , come-afters(include self)(brothers)|maxson(paths) , sex
 
stack<pic> brother;
stack<pic> path;
 
inline pic makepic(int deep,int cas,int sex)
{
    return make_pair(make_pair(deep ,cas) ,sex);
}
 
inline void getlinefree()
{
    while(getchar()!='\n');return;
}
 
int main()
{   
	freopen("throne.in", "r", stdin);
	freopen("throne.out", "w", stdout);

    scanf("%d %d",&n,&m);
     
    int deep = 0;
     
    int tempi;int tempc;
    while(thisid != m){ //find path to purpose root
        while(1) //find ancester to purpose root
        {
            {
                scanf("%d %d\n",&tempi,&tempc);
                thisid++;
                //printf("get id = %d,%d,%c ",thisid,tempi,tempc);
            }
            maxson = thisid + tempi;
            if(maxson >= m) //is an ancestor
            {
                path.push(makepic(deep,maxson,tempc));
                deep++;
                //printf("is an ancestor\n");
                break;
            }else{
                brother.push(makepic(deep,tempi + 1,tempc));
                //printf("is a brother\n");
                for(int i = 0;i < tempi;i++)
                {
                    getlinefree();thisid++;
                }
            }
        }
    }//gotcha!
    //printf("gotcha!\n");
    deep--;
    //at this path.top() = m,thisid = m,seek = m + 1
     
    pic top;
    int ans = 0;
    while(deep>0)
    {
        int thisdelta = 0;
        top = path.top();path.pop();
        while(thisid < top.first.second/*maxson*/)
        {
            getlinefree();thisid++;
        }
        if(top.second == 0)//is female ,count all her younger brother
        {
            while((!brother.empty())&&brother.top().first.first == deep)brother.pop();
            int maxbrother = path.top().first.second;
             
            while(thisid < maxbrother)
            {
                int tempi;int tempc;
                {
                    scanf("%d %d\n",&tempi,&tempc);
                    thisid++;
                }
                if(tempc == 1)
                {
                    thisdelta += (tempi + 1);
                }
                for(int i = 0;i < tempi;i++)
                {
                    getlinefree();thisid++;
                }
            }
        }else{              //is male ,count all his elder sister 
            pic tempbrother;
            while((!brother.empty())&&(tempbrother = brother.top()).first.first == deep)
            {
                brother.pop();
                if(tempbrother.second == 0)
                {
                    thisdelta -= tempbrother.first.second;
                }
            }
        }
        //printf("deep = %d,ans = %d\n",deep,thisdelta);
        ans+=thisdelta;
        deep--;
    }
     
    printf("%d\n",ans);
    return 0;
}
