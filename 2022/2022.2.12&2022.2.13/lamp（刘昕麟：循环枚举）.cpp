#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <ctime>
//#include <cmath>

/*
循环迭代版本
日期:2.12 
*/
using namespace std;

int a[10][10]={0};//用于记录初始灯的状态 
int b[10][10]={0};//用于记录尝试的灯的状态 
void change(int x,int y){//用于改变b数组中x,y位置灯的状态 
	if(b[x][y]==0) b[x][y]=1;//(0改1) 
	else if(b[x][y]==1) b[x][y]=0;//(1改0)
}
 
void an(int x,int y){//按下x,y位置改变的灯 
	change(x,y);//改变中心 
	change(x+1,y);//↑
	change(x-1,y);//↓ 
	change(x,y+1);//←  
	change(x,y-1);//→ 
}//因为我存数是1,1开始的，0行0列留空 

void la(){//用于解决一次 
	for(int i=1;i<=5;i++){
		for(int j=1;j<=6;j++){
			cin >> a[i][j];//读入a数组 
		}
	}
	for(int a1=0;a1<2;a1++){//a1-a5用于循环第一列5个按钮的状态0或1 
		for(int a2=0;a2<2;a2++){
			for(int a3=0;a3<2;a3++){
				for(int a4=0;a4<2;a4++){
					for(int a5=0;a5<2;a5++){
						int c[10][10]={0};//c数组存那些按钮按下 
						//重置b数组 
						for(int i=1;i<=5;i++){
							for(int j=1;j<=6;j++){
								b[i][j]=a[i][j];
							}
						}
						//把循环出来的按钮状态按下
						//按按钮 
						if(a1){
							an(1,1);c[1][1]=1;
						} 
						if(a2){
							an(2,1);c[2][1]=1;
						} 
						if(a3){
							an(3,1);c[3][1]=1;
						} 
						if(a4){
							an(4,1);c[4][1]=1;
						} 
						if(a5){
							an(5,1);c[5][1]=1;
						} 
						//循环看下一行 
						for(int i=2;i<=6;i++){//i是行    
							for(int j=1;j<=5;j++){//j是列 
								if(b[j][i-1]==1){ 
									an(j,i);c[j][i]=1;
								}
							}
						}
						//看最后一列 
						int flag=1;//flag来记录是不是正确答案  
						for(int i=1;i<=5;i++){
							if(b[i][6]==1) flag=0;//如果最后一行还有亮的 
						}
						//如果成功
						if(flag){
							for(int i=1;i<=5;i++){//i行 
								for(int j=1;j<=6;j++){//j列 
									cout << c[i][j] << " ";//输出 
								}
								cout << endl;
							}
							return;
						}					
					}
				}
			}
		}
	}
}

int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	int N;//要解决的案例数 
	cin >> N;
	for(int i=1;i<=N;i++){
		printf("PUZZLE #%d\n",i);//先输出 
		la();//调用函数 
	}			
	return 0;
}
