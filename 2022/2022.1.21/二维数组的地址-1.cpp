#include <iostream>
using namespace std;

int main()
{
	int a[3][4]={{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
	
	cout<<" a = " << a << endl;
	cout<<" &a[0] = "<<&a[0]<<endl<<endl;
	
	cout<<" a+1 = "<<a+1<<endl;
	cout<<" &a[0]+1 = "<<&a[0]+1<<endl<<endl;
	
	cout<<" *a = "<<*a<<endl;
	cout<<" a[0] = "<<a[0]<<endl;
	
	cout<<" &a[0][0] = "<<&a[0][0]<<endl<<endl;
	cout<<" *a+1 = "<<*a+1<<endl;
	
	cout<<" a[0]+1 = "<<a[0]+1<<endl;
	cout<<"&a[0][0]+1 = "<<&a[0][0]+1<<endl<<endl;
	
	return 0;
}
