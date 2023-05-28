#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		bool end;
};
int main(){
	node *head=new node,*temp;
	(*head).next=NULL;
	temp=head;
	head->end=1;
	int stemp;
	cin>>stemp;
	while(stemp!=-1){
		temp->end=0;
		temp->data=stemp;
		temp->next=new node;
		temp->next->end=1;
		temp=temp->next;
		cin>>stemp;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		if(m==1){
			int a;
			cin>>a;
			node *temp2=head;
			for(int i=1;i<a;i++){
				temp2=temp2->next;
			}
			cout<<temp2->data<<endl;
		}
		if(m==2){
			int a;
			cin>>a;
			if(a==1){
				node *temp10;
				temp10=(head->next);
				delete head;
				head=temp10;
				cout<<endl;
				continue;
			}
			node *temp2=head;
			for(int i=1;i<a-1;i++){
				temp2=temp2->next;
			}
			node *temp3=(temp2->next)->next;
			delete (temp2->next);
			temp2->next=temp3;
			cout<<endl;
		}
		if(m==3){
			node *temp11=head;
			for(temp11=head;(temp11->end)==0;temp11=temp11->next){
				cout<<temp11->data<<' ';
			}
			cout<<endl;
		}
		if(m==4){
			int a;
			cin>>a;
			node *temp11=head;
			int i=1;
			for(temp11=head;(temp11->end)==0;temp11=temp11->next,i++){
				if(temp11->data==a){
					cout<<i<<' ';
				}
			}
			cout<<endl;
		}
		if(m==5){
			int a,b;
			cin>>a;
			node *temp11=head;
			for(int i=1;i<a;i++){
				temp11=temp11->next;
			}
			node *temp=new node;
			temp->next=temp11->next;
			temp11->next=temp;
			cin>>temp->data;
		}
	}
	return 0;
}

