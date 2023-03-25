    #include <iostream>
    using namespace std;
    int main(){
        int n;
        cin>>n;
        int temp;
        for(temp=1;n>0;n=n-temp){
            temp++;
        }
        n+=temp;
        n--;
        cout<<n<<'/'<<temp-n+1;
    }