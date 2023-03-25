#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
void sort(int *,int *);
int a[11];
int main()
{
    srand(time(NULL));
    int n=rand()%(100-10+1)+10;
    for(int i=1;i<=n;i++){
        a[i]=rand()%(1000-(-1000)+1)+(-1000);//(-1000<a[i]<1000)
    }
    cout<<"begin:";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    sort(a+1,a+n);//ÅÅÐò 
    cout<<"end:";
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
void sort(int *begin,int *end){
    for(int *i=begin;i<=end;i++){
        for(int *j=i;j<=end;j++){
            if(*i<*j){
                swap(*i,*j);
            }
        }
    }
    return;
}
