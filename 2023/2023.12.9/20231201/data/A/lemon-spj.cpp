#include<bits/stdc++.h>
using namespace std;

FILE *fscore, *freport, *fstd, *fin, *fout;
int score;

inline long long Abs(long long a)
{
       if (a>=0) return a;
       return -a;
}

bool Check()
{
	double a,b;
	int t=0;
	fscanf(fstd,"%lf",&a);
	fscanf(fout,"%lf",&b);
	if(fabs(a-b)>0.0001)return false;
      else return true;
}
int s[100002],n,k;
long long ans1,ans2;
int main(int argc, char *argv[])
{
    fscore = fopen(argv[5], "w");
    freport = fopen(argv[6], "w");
    fstd = fopen(argv[3], "r");
    score = atoi(argv[4]);
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "r");
    fscanf(fin,"%d%d",&n,&k);
    fscanf(fstd,"%lld",&ans1);
    fscanf(fout,"%lld",&ans2);
    if(ans1^ans2){
		fprintf(fscore, "%d", 0);
		fprintf(freport, "Holy Shik!");
		fclose(fscore);
		fclose(freport);
    	return 0;
	}
    for(int i=1;i<=n;++i){
    	fscanf(fout,"%d",&s[i]);
    	if(s[i]!=0&&s[i]!=1){
    		fprintf(fscore, "%d", 0);
			fprintf(freport, "Gina!");
			fclose(fscore);
			fclose(freport);
			return 0;
		}
	}
	for(int i=1;i<=n;++i)k-=s[i];
	if(k!=0){
		fprintf(fscore, "%d", 0);
		fprintf(freport, "NIT!");
		fclose(fscore);
		fclose(freport);
		return 0;	
	}
	int c[2]={1,0},o=0;
	for(int i=1;i<=n;++i)o^=s[i],++c[o];
	if(1ll*c[0]*c[1]!=ans1){
		fprintf(fscore, "%d", 0);
		fprintf(freport, "114514!");
		fclose(fscore);
		fclose(freport);
		return 0;
	}
	fprintf(fscore, "%d", score);
	fprintf(freport, "orz!!!!!!!!!!!!!!!");
	fclose(fscore);
	fclose(freport);
	return 0;
}
