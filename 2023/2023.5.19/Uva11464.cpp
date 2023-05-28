#include <iostream>
#include <cstdio>
#include <cstring>
inline int read();
int map1[20][20];
int map2[20][20];
int ans=0,n;
int ans2=0;
int solve(){//����ö�ٳ��ĵ�һ���Ƴ�����ķ���
    int temp=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){//map2�����ڴ˷�Χ�޸ģ������������κ�Ӱ��
            map2[i][j]=map1[i-1][j]+map1[i][j-1]+map1[i][j+1]+map1[i+1][j];//���л���ʵ�map1[n+1]����һ�����գ����㼴��
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map2[i-1][j]%2){
                if(map1[i][j]==1){//ѹ�������ˣ���������
                    return 0x3f3f3f3f;
                }
                map2[i-1][j]++;
                map2[i+1][j]++;
                map2[i][j+1]++;
                temp++;
                map2[i][j-1]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(map2[n][i]%2){//��Ҫ©��
            return 0x3f3f3f3f;
        }
    }
    return temp;
}
void dfs(int step,int maxn){
    if(step==maxn+1){
        ans=std::min(ans,ans2+solve());//ans������С�𰸣�ans2�����һ��
        return ;
    }
    dfs(step+1,maxn);
    if(map1[1][step]==0){
        map1[1][step]=1;
        ans2++;
        dfs(step+1,maxn);
        ans2--;//һ��Ҫ��0��qwq
        map1[1][step]=0;
    }
    return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int T=read();
    for(int TT=1;TT<=T;TT++){
        ans=0x3f3f3f3f;//��ʼ��qwq
        n=read();
        memset(map1,0,sizeof(map1));
        memset(map2,0,sizeof(map2));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map1[i][j]=read();
            }
        }
        dfs(1,n);
        if(ans==0x3f3f3f3f){
            ans=-1;
        }
        printf("Case %d: %d\n",TT,ans);
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
    Exercise
Description:
    ��һ��01�����е�����0���1��ʹ��ÿ���������������ĺͶ���ż�������ٸı���ٸ�0
Example:
	1:
		In:
            3
            3
            0 0 0
            0 0 0
            0 0 0
            3
            0 0 0
            1 0 0
            0 0 0
            3
            1 1 1
            1 1 1
            0 0 0
		Out:
            Case 1: 0
            Case 2: 3
            Case 3: -1
More:
    ö�ٵ�һ�к�ֱ�������
*/