/*
	分析 ：等级1是一个2*2的格子，即被分为2行2列。
	       等级2是一个4*4的格子，即被分为4行4列。
	       等级1是如何转变为等级2的呢？
	       
	我们将等级 1（2*2的格子）按顺时针分为4个区域。
	将等级 2（4*4的格子）按顺时针分为4个区域（每个区域是 2*2格子），不难看出，等级2的2区域，3区域完全是等级1的形状。
	1区域是等级1的顺时针旋转90°，4区域则是1区域的轴对称图形。
	
	我们可以得到一个非规律：(注：n是等级)
	如果一个点在第4区域，那么(2^n)+1=这个房子的(x+y)。且如果是第四块，先对上一等级逆时针旋转，即先顺时针旋转再中心对称。
    如果一个点在第1区域，旋转后横坐标变成纵坐标。
　　如果一个点在第2区域，形状和上一等级（现在是等级2，上一等级即等级1）一样无需变化，只需要求出上一等级的横坐标。
　　如果一个点在第3区域，形状也和上一等级一样，求出上一等级横坐标还要加上半个边长。
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#define LL long long int
using namespace std;
int base_x[5]={0,1,1,2,2};//第一等级为基底，这是等级1四个房子的所在行，base_y是四个房子的所在列，数组的[0]默认不放为[0]。
int base_y[5]={0,1,2,2,1};//任何等级都由第一等级推过去 
long long int k,a,b,t;
LL search_y(LL k,LL n); //声明函数 
double dis(LL x1,LL y1,LL x2,LL y2){return sqrt(pow(x1-x2,2)+pow(y1-y2,2))*10;}//计算距离函数 
LL search_x(LL k,LL n)
{
    if(k==1)return base_x[n];//边界 如果是第一等级 直接返回答案 即该标号横坐标 
    else{
        LL map=pow(2,k<<1);//地图的大小 即k等级的动物园共有几个房屋 
        int block=(n%(map>>2)==0)?(n/(map>>2)):(n/(map>>2))+1;
        //计算标号为n的房屋在地图的哪一个方位(左上右上左下右下)特殊条件特殊判断 
        if(block==1)return search_y(k-1,n);//分类搜索答案 
        //如果是第一块 旋转后横坐标变成纵坐标 
        else if(block==2)return search_x(k-1,(n%(map>>2)==0)?n/2:n%(map>>2));
        //如果是第二块 形状和上一等级一样无需变化 只是求出上一等级的横坐标即可 
        else if(block==3)return search_x(k-1,n%(map>>1))+pow(2,k-1);
        //如果是第三块 形状也一样 求出上一等级横坐标还要加上半个边长 
        else if(block==4)return pow(2,k)+1-search_y(k-1,n%(map*3/4));
        //如果是第四块 逆时针旋转 先顺时针旋转再中心对称。(2^n)+1=这个房子的(x+y)
    }
}/*注释同上*/
LL search_y(LL k,LL n)
{
    if(k==1)return base_y[n];
    else{
        LL map=pow(2,k<<1);
        int block=(n%(map>>2)==0)?(n/(map>>2)):(n/(map>>2))+1;
        if(block==1)return search_x(k-1,n);
        else if(block==2)return search_y(k-1,(n%(map>>2)==0)?n/2:n%(map>>2))+pow(2,k-1);
        else if(block==3)return search_y(k-1,n%(map>>1))+pow(2,k-1);
        else if(block==4)return pow(2,k-1)+1-search_x(k-1,n%(map*3/4));
    }
}
/*注释同上*/
int main(void)
{
    freopen("stupid.in","r",stdin);
    freopen("stupid.out","w",stdout);
	cin>>t;//数据总量 
    while(t--){
        
        cin>>k>>a>>b;//读入等级数 StupidCat和Doge的房屋编号 
        
        LL x1=search_x(k,a);//求出Cat的房屋横坐标 
        LL y1=search_y(k,a);//求出Cat的房屋纵坐标 
        LL x2=search_x(k,b);//求出Doge的房屋横坐标 
        LL y2=search_y(k,b);//求出Doge的房屋纵坐标
        
        double ans=dis(x1,y1,x2,y2);//计算两者之间的距离 
        
        LL temp=ans;//以下是四舍五入计算 
        cout<<((ans>=temp+0.5)?(temp+1):temp)<<endl;        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
