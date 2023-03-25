#include <iostream>
#include <cstdio>
inline int read();
int map[5005][5005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("laserbomb.in","r",stdin);
	freopen("laserbomb.out","w",stdout);
	#endif
    int n=read(),r=read();
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        map[x][y]+=read();
    }
    int _max=-40000;
    int i=-1;
    int j=-1;
    int temp1=0,temp2=0;
    for(int mi=1;mi<=r;mi++){
        for(int mj=1;mj<=r;mj++){
            temp1+=map[i+mi][j+mj];
        }
    }
    temp2=temp1;
    _max=std::max(_max,temp2);
    for(j=0;j<=5001-r;j++){
        for(int mi=1;mi<=r;mi++){
            temp2-=map[mi+i][j];
            temp2+=map[mi+i][j+r];
        }
        _max=std::max(_max,temp2);
    }
    for(i=0;i<=5001-r;i++){
        temp2=temp1;
        for(int mj=0;mj<r;mj++){
            temp2-=map[i][mj];
            temp2+=map[i+r][mj];
        }
        _max=std::max(_max,temp2);
        temp1=temp2;
        for(j=0;j<=5001-r;j++){
            for(int mi=1;mi<=r;mi++){
                temp2-=map[mi+i][j];
                temp2+=map[mi+i][j+r];
            }
            _max=std::max(_max,temp2);
        }
    }
    printf("%d",_max);
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
封控在家可能 5天，即将死亡，啊啊啊啊啊啊啊啊啊啊啊，全体去看QQ群。呜呜
    这次的题从一位前缀和到三位前缀和，感觉不算特别难的算法，三维可以通过二维和一维的递推式猜，还是很好猜的
*/


