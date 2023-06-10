#include <testlib>
#include <stack>
std::stack<int>a;
int seq[1000005];
bool fu[1000005];
std::string aa;
std::string b;
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    aa=ouf.readWord();
    b=ans.readWord();
    if(aa=="NO"){
        if(b=="NO"){
            quitf(_ok, "Accept.");
        }else{
             quitf(_wa, "Wrong Answer");
        }
    }
    if(b=="NO"){
    	quitf(_wa,"Wrong Answer");
	}
    int n=inf.readInt();
    for(int i=1;i<=n;i++){
        seq[i]=inf.readInt();
    }
    int m=inf.readInt();
    for(int i=1;i<=m;i++){
        fu[inf.readInt()]=1;
    }
    int j=1;
    do{
        int s=0;
        if(aa[0]!='+'&&aa[0]!='-'){
        	quitf(_wa,"Wrong Answer");
		}
        for(int i=1;i<aa.size();i++){
        	if(1ll*s*10>(1ll<<32)) quitf(_wa,"Wrong Answer");
        	if('0'>aa[i]||aa[i]>'9'){
        		quitf(_wa,"Wrong Answer");
			}
            s=s*10;
            s+=aa[i]-'0';
        }
        if(s!=seq[j]){
            quitf(_wa, "Wrong Answer");
        }
        if(fu[j]&&aa[0]!='-'){
            quitf(_wa, "Wrong Answer");
        }
        if(aa[0]=='-'){
            if(a.size()==0){
                quitf(_wa, "Wrong Answer");
            }else if(a.top()!=s){
                quitf(_wa, "Wrong Answer");
            }else{
                a.pop();
            }
        }else{
            a.push(s);
        }
        j++;
        aa=ouf.readWord();
    }while(!ouf.eof()&&j<=n+2);
    if(a.size()==0&&j==n+1){
        quitf(_ok, "Accept.");
    }else{
        quitf(_wa, "Wrong Answer");
    }
}
