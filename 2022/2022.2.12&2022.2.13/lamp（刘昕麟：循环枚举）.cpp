#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <ctime>
//#include <cmath>

/*
ѭ�������汾
����:2.12 
*/
using namespace std;

int a[10][10]={0};//���ڼ�¼��ʼ�Ƶ�״̬ 
int b[10][10]={0};//���ڼ�¼���ԵĵƵ�״̬ 
void change(int x,int y){//���ڸı�b������x,yλ�õƵ�״̬ 
	if(b[x][y]==0) b[x][y]=1;//(0��1) 
	else if(b[x][y]==1) b[x][y]=0;//(1��0)
}
 
void an(int x,int y){//����x,yλ�øı�ĵ� 
	change(x,y);//�ı����� 
	change(x+1,y);//��
	change(x-1,y);//�� 
	change(x,y+1);//��  
	change(x,y-1);//�� 
}//��Ϊ�Ҵ�����1,1��ʼ�ģ�0��0������ 

void la(){//���ڽ��һ�� 
	for(int i=1;i<=5;i++){
		for(int j=1;j<=6;j++){
			cin >> a[i][j];//����a���� 
		}
	}
	for(int a1=0;a1<2;a1++){//a1-a5����ѭ����һ��5����ť��״̬0��1 
		for(int a2=0;a2<2;a2++){
			for(int a3=0;a3<2;a3++){
				for(int a4=0;a4<2;a4++){
					for(int a5=0;a5<2;a5++){
						int c[10][10]={0};//c�������Щ��ť���� 
						//����b���� 
						for(int i=1;i<=5;i++){
							for(int j=1;j<=6;j++){
								b[i][j]=a[i][j];
							}
						}
						//��ѭ�������İ�ť״̬����
						//����ť 
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
						//ѭ������һ�� 
						for(int i=2;i<=6;i++){//i����    
							for(int j=1;j<=5;j++){//j���� 
								if(b[j][i-1]==1){ 
									an(j,i);c[j][i]=1;
								}
							}
						}
						//�����һ�� 
						int flag=1;//flag����¼�ǲ�����ȷ��  
						for(int i=1;i<=5;i++){
							if(b[i][6]==1) flag=0;//������һ�л������� 
						}
						//����ɹ�
						if(flag){
							for(int i=1;i<=5;i++){//i�� 
								for(int j=1;j<=6;j++){//j�� 
									cout << c[i][j] << " ";//��� 
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
	int N;//Ҫ����İ����� 
	cin >> N;
	for(int i=1;i<=N;i++){
		printf("PUZZLE #%d\n",i);//����� 
		la();//���ú��� 
	}			
	return 0;
}
