//1001 1010 0001 1 
//1001 0101 1101 1
//���ǹ۲췢���������ڶ����ƶ��ɱ�ʾΪ������ʽ 
//1001 xxxx xxxx 0/1 xxxx xxxx 1001 
//���ǹ۲췢�ֶ�����ֻ��ö�� "xxxx xxxx" ��"0/1"�Ĳ��� 
#include<iostream>
#include<cstdio>
#define int unsigned long long
using namespace std;
signed main(){
	register int i,j,x,o,s,n,y,r;
	//"xxxx xxxx"ȡֵ,ֻ����һ��"xxxx xxxx" ��СΪ 93��19641010 == 1001 01011101 1 00101011 0010�������Ϊ 161 ��20200724 == 1001 10100001 1 11010001 0100��
	for(i=93;i<=161;++i){//ö�� "xxxx xxxx"
		x=i;j=0;
		while(x>0){
			j|=x&1;
			j<<=1;
			x>>=1;
			
		}x=i;j>>=1;
		for(o=0;o<2;++o){//ö�� "0/1"
			// ƴ�Ӹ����� 
			//  1001      xxxx      0/1      xxxx    1001
			s=(9<<21) | (x<<13) | (o<<12) | (j<<4) | 9;
			if(s<19641010||s>20200724) continue;
			n=s/10000;		//�� 
			y=(s%10000)/100;//�� 
			r=s%100;		//�� 
			if(y<1||y>12) continue;
			if(y<8){//8����ǰ ����Ϊ ���� 
				if(y&1&&r<32&&r>0) printf("%u\n",s);
				else if(y==2){ 
					//���ڶ�������������⴦�� 
					//��Ϊ1966~2020 ���ܱ� 100 ������ֻ�� 2000,�����պ� �ܱ� 400 ����
					//����ֻ���ж��ܷ� 4 ���� 
					if(n%4==0&&r>0&&r<30) printf("%u\n",s);
					else if(r>0&&r<29) printf("%u\n",s);
				}
				else if(!(y&1)&&r<31&&r>0) printf("%u\n",s);
			}//8���Ժ� ����Ϊ ż�� 
			else if(y&1&&r<31&&r>0) printf("%u\n",s);
			else if(!(y&1)&&r<32&&r>0) printf("%u\n",s);
		}
	}
	return 0;
}
