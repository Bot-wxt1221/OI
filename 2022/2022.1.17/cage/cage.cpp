#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("cage.in","r",stdin);
    freopen("cage.out","w",stdout);
    int m,n;
    cin>>m;
    for(int b=0;b<=m;b++){
        cin>>n;
        if(n%2==1){//������nһ����ż���������޽� 
        	cout<<"0 0\n";
        }else if(n%4){//���پ���4ֻ��   ��ྡ��2ֻ�� 
        	cout<<n/4+1<<' '<<n/2<<endl;
        }else{
        	cout<<n/4<<' '<<n/2<<endl;
        }
    }
    return 0;
}
