#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,K,ls[200002],rs[200002],a[200002],b[200002],f[200002],cc,tot;
struct node{
	int x,y;
	bool operator <(const node A)const{return x==A.x?y<A.y:x<A.x;}
};
multiset<node>S[200002];
multiset<node>::iterator it,it1,it2,it3,it4;
inline void find(multiset<node>&A,re int x){
	it1=A.upper_bound((node){x+1,-1});
}
inline bool ck(multiset<node>&A,multiset<node>&B){
	cc=0;
	for(it=B.begin();it!=B.end();++it){
		find(A,(*it).x);
		if(it1!=A.begin()){
			--it1;
			if((*it1).y>=(*it).x)return 1;
			++it1;
		}
		if(it1!=A.end()&&(*it1).x<=(*it).y)return 1;
		++tot;
	}
	return 0;
}
inline void cg1(multiset<node>&A,multiset<node>&B){
	it2=A.begin(),cc=0;
	for(it=B.begin();it!=B.end();++it){
		find(A,(*it).x);
		while(it2!=A.end()&&(*it2).y<(*it).x)it3=it2,++it2,A.erase(it3);
		if(it1!=A.begin()){
			--it1;
			re int xx=-1;
			if((*it1).y>=(*it).x)A.insert((node){(*it).x,xx=min((*it).y,(*it1).y)}),A.erase(it1);
			if(~xx&&(*it1).y!=xx)A.insert((node){xx+1,(*it1).y});
		}
		find(A,(*it).y);
		if(it1!=A.begin()){
			--it1;
			re int xx=-1;
			if((*it1).x<=(*it).y)A.insert((node){(*it1).x,xx=min((*it1).y,(*it).y)});
			if(~xx&&(*it1).y!=xx)A.insert((node){xx+1,(*it1).y});
			A.erase(it1);
		}
		it2=A.upper_bound((node){(*it).y+1,-1});
		++tot;
	}
	while(it2!=A.end()){
		it3=it2,++it2;
		A.erase(it3);
	}
}
inline void cg2(multiset<node>&A,multiset<node>&B){
	for(it=B.begin();it!=B.end();++it){
		re int l=(*it).x,r=(*it).y;
		find(A,l);
		if(it1!=A.begin())--it1,l=max(l,(*it1).y+1),++it1;
		while(it1!=A.end()&&(*it1).y<=r)it2=it1,++it1,A.erase(it2);
		if(it1!=A.end())r=min(r,(*it1).x-1);
		if(l<=r)A.insert((node){l,r});
		++tot;
	}
}
inline void dfs(re int x){
	if(!ls[x])swap(ls[x],rs[x]);
	if(ls[x])dfs(ls[x]);
	if(rs[x])dfs(rs[x]);
	if(a[x]>=b[x]){
		S[x].insert((node){0,K-a[x]-1});
		if(b[x])S[x].insert((node){K-b[x],K-1});
	}
	else S[x].insert((node){K-b[x],K-a[x]-1});
	if(!ls[x])return;
	if(!rs[x]){
		if(ck(S[ls[x]],S[x]))cg1(S[ls[x]],S[x]),f[x]=f[ls[x]];
		else cg2(S[ls[x]],S[x]),f[x]=f[ls[x]]+1;
		S[x].swap(S[ls[x]]);
		return;
	}
	multiset<node>tmp1,tmp2;
	if(S[ls[x]].size()<S[rs[x]].size())swap(ls[x],rs[x]);
	if(ck(S[x],S[rs[x]])){
		tmp1=S[rs[x]],cg1(tmp1,S[x]);
		if(ck(tmp1,S[ls[x]]))cg1(S[ls[x]],tmp1),S[x].swap(S[ls[x]]),f[x]=f[ls[x]]+f[rs[x]];
		else{
			tmp2=S[rs[x]],cg2(tmp2,S[x]),cg1(S[ls[x]],tmp2),cg2(S[ls[x]],tmp1);
			S[x].swap(S[ls[x]]),f[x]=f[ls[x]]+f[rs[x]]+1;
		}
	}
	else if(ck(S[ls[x]],S[x])||ck(S[ls[x]],S[rs[x]])){
		cg2(S[x],S[rs[x]]),cg1(S[ls[x]],S[x]);
		swap(S[x],S[ls[x]]),f[x]=f[ls[x]]+f[rs[x]]+1;
	}
	else{
		cg2(S[ls[x]],S[x]),cg2(S[ls[x]],S[rs[x]]);
		S[x].swap(S[ls[x]]),f[x]=f[ls[x]]+f[rs[x]]+2;
	}
}
int main(){
	freopen("rugby.in","r",stdin);
	freopen("rugby.out","w",stdout);
	n=read(),K=read();
	for(re int i=1;i<=n;++i)a[i]=read(),b[i]=read(),ls[i]=read(),rs[i]=read();
	dfs(1);
	if((*S[1].begin()).x>0)++f[1];
	printf("%d\n",f[1]);
}
