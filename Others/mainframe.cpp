#include <iostream> 
#include <cstdio> 
#include <queue> 
using namespace std;
 class node{ public: int a,b,t,u,v,w,x,number; }a[10005]; 
 bool operator<(node a,node b){ return a.v<b.v; } 
 priority_queue<node>h; queue<node>wait; bool vised[10005];
 int main(){ 
 ios::sync_with_stdio(false); 
 int f,na=0; 
 do{
	 na++;
 memset(vised,0,sizeof(vised)); 
 int ans=0; 
 cin>>f; 
 int n,m,l; 
 cin>>m>>n>>l; 
 for(int i=1;i<=l;i++){ 
 cin>>a[i].a>>a[i].b>>a[i].t>>a[i].u>>a[i].v>>a[i].w>>a[i].x; a[i].number=i; }
 while(h.size()>0){ h.pop(); } 
 for(int fi=1;fi<=f;fi++){ for(int j=1;j<=l;j++){ if(a[j].t==fi){ h.push(a[j]); } } 
 int mm=m,mn=n; int size=wait.size(); 
 for(int i=1;i<=size;i++){ node temp=wait.back(); 
 if(temp.a<=mm&&temp.b<=mn){ 
 if((temp.u-1)>=fi){ 
 ans+=temp.v+temp.w*(temp.u-fi-1); }else{ 
 ans+=temp.v-(temp.x)*(fi-temp.u+1); } vised[temp.number]=1; mm-=temp.a; mn-=temp.b; }else{
  wait.push(temp); } wait.pop(); } while(h.size()>0){ node temp=h.top(); if(temp.a<=mm&&temp.b<=mn){ 
  if((temp.u-1)>=fi){ ans+=temp.v+temp.w*(temp.u-fi-1); }else{ ans+=temp.v-(temp.x)*(fi-temp.u+1); } vised[temp.number]=1; mm-=temp.a; mn-=temp.b; }else{ wait.push(temp); } h.pop(); } 
  } for(int i=1;i<=l;i++){ if(!vised[i]&&a[i].u<=f){
   ans-=(a[i].x)*(f-a[i].u); } } printf("Case %d: %d",na,ans) }while(f!=0);
   }
