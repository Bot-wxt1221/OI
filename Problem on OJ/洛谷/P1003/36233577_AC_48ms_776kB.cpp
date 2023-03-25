#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int b[a][4],x,y;
    for(int i=0;i<a;i++)
    cin>>b[i][0]>>b[i][1]>>b[i][2]>>b[i][3];
    cin>>x>>y;
    for(int i=a-1;i>=0;i--)
    {
        if(x<=b[i][2]+b[i][0]&&x>=b[i][0]&&y<=b[i][3]+b[i][1]&&y>=b[i][1])//没超出范围 
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}