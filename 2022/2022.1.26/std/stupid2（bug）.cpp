/*
	���� ���ȼ�1��һ��2*2�ĸ��ӣ�������Ϊ2��2�С�
	       �ȼ�2��һ��4*4�ĸ��ӣ�������Ϊ4��4�С�
	       �ȼ�1�����ת��Ϊ�ȼ�2���أ�
	       
	���ǽ��ȼ� 1��2*2�ĸ��ӣ���˳ʱ���Ϊ4������
	���ȼ� 2��4*4�ĸ��ӣ���˳ʱ���Ϊ4������ÿ�������� 2*2���ӣ������ѿ������ȼ�2��2����3������ȫ�ǵȼ�1����״��
	1�����ǵȼ�1��˳ʱ����ת90�㣬4��������1�������Գ�ͼ�Ρ�
	
	���ǿ��Եõ�һ���ǹ��ɣ�(ע��n�ǵȼ�)
	���һ�����ڵ�4������ô(2^n)+1=������ӵ�(x+y)��������ǵ��Ŀ飬�ȶ���һ�ȼ���ʱ����ת������˳ʱ����ת�����ĶԳơ�
    ���һ�����ڵ�1������ת��������������ꡣ
�������һ�����ڵ�2������״����һ�ȼ��������ǵȼ�2����һ�ȼ����ȼ�1��һ������仯��ֻ��Ҫ�����һ�ȼ��ĺ����ꡣ
�������һ�����ڵ�3������״Ҳ����һ�ȼ�һ���������һ�ȼ������껹Ҫ���ϰ���߳���
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#define LL long long int
using namespace std;
int base_x[5]={0,1,1,2,2};//��һ�ȼ�Ϊ���ף����ǵȼ�1�ĸ����ӵ������У�base_y���ĸ����ӵ������У������[0]Ĭ�ϲ���Ϊ[0]��
int base_y[5]={0,1,2,2,1};//�κεȼ����ɵ�һ�ȼ��ƹ�ȥ 
long long int k,a,b,t;
LL search_y(LL k,LL n); //�������� 
double dis(LL x1,LL y1,LL x2,LL y2){return sqrt(pow(x1-x2,2)+pow(y1-y2,2))*10;}//������뺯�� 
LL search_x(LL k,LL n)
{
    if(k==1)return base_x[n];//�߽� ����ǵ�һ�ȼ� ֱ�ӷ��ش� ���ñ�ź����� 
    else{
        LL map=pow(2,k<<1);//��ͼ�Ĵ�С ��k�ȼ��Ķ���԰���м������� 
        int block=(n%(map>>2)==0)?(n/(map>>2)):(n/(map>>2))+1;
        //������Ϊn�ķ����ڵ�ͼ����һ����λ(����������������)�������������ж� 
        if(block==1)return search_y(k-1,n);//���������� 
        //����ǵ�һ�� ��ת��������������� 
        else if(block==2)return search_x(k-1,(n%(map>>2)==0)?n/2:n%(map>>2));
        //����ǵڶ��� ��״����һ�ȼ�һ������仯 ֻ�������һ�ȼ��ĺ����꼴�� 
        else if(block==3)return search_x(k-1,n%(map>>1))+pow(2,k-1);
        //����ǵ����� ��״Ҳһ�� �����һ�ȼ������껹Ҫ���ϰ���߳� 
        else if(block==4)return pow(2,k)+1-search_y(k-1,n%(map*3/4));
        //����ǵ��Ŀ� ��ʱ����ת ��˳ʱ����ת�����ĶԳơ�(2^n)+1=������ӵ�(x+y)
    }
}/*ע��ͬ��*/
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
/*ע��ͬ��*/
int main(void)
{
    freopen("stupid.in","r",stdin);
    freopen("stupid.out","w",stdout);
	cin>>t;//�������� 
    while(t--){
        
        cin>>k>>a>>b;//����ȼ��� StupidCat��Doge�ķ��ݱ�� 
        
        LL x1=search_x(k,a);//���Cat�ķ��ݺ����� 
        LL y1=search_y(k,a);//���Cat�ķ��������� 
        LL x2=search_x(k,b);//���Doge�ķ��ݺ����� 
        LL y2=search_y(k,b);//���Doge�ķ���������
        
        double ans=dis(x1,y1,x2,y2);//��������֮��ľ��� 
        
        LL temp=ans;//����������������� 
        cout<<((ans>=temp+0.5)?(temp+1):temp)<<endl;        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
