#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long t,n,ans=1;
    cin>>t;
    for(long long i=1;i<=t;i++){
        cin>>n;
        long long int sum = 0, count = 0,temp;
		while(n)
		{
			temp = n % 10;
			if (temp < 7)
				sum += temp * pow(9, count);
			else
				sum += (temp-1) * pow(9, count);
			n /= 10;
			count++;
		}
		cout<<sum<<endl;
    }
    return 0;
}