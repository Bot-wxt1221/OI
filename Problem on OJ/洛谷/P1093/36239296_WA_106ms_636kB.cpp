#include <cstdio>
#include <algorithm>
using namespace std;
class stu{
    public:
        int ch;
        int ma;
        int en;
        int num;
        int he;
};
bool cmp(stu a,stu b);
stu a[305];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i].ch,&a[i].ma,&a[i].en);
        a[i].num=i;
        a[i].he=a[i].ch+a[i].ma;a[i].en;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<5;i++){
        printf("%d %d\n",a[i].num,a[i].he);
    }
}
bool cmp(stu a,stu b){
    if(a.he!=b.he){
        return a.he>b.he;
    }
    if(a.ch!=b.ch){
        return a.ch>b.ch;
    }
    else{
        return a.num>b.num;
    }
}