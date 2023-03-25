#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 4;
int mg[MAX][MAX] = {
	{0, 1, 0, 0},
 	{0, 0, 1, 1},
 	{0, 1, 0, 0},
 	{0, 0, 0, 0}
};
int m = 4, n = 4;
int dx[] = {-1, 0, 1, 0};   	//x·½ÏòµÄÆ«ÒÆÁ¿
int dy[] = {0, 1, 0, -1};   	//y·½ÏòµÄÆ«ÒÆÁ¿
struct Box{				//·½¿éÀàĞÍ
	int i;				//·½¿éµÄĞĞºÅ
   	int j;				//·½¿éµÄÁĞºÅ
   	int di;				//diÊÇÏÂÒ»¸öÏàÁÚ¿É×ß·½Î»µÄ·½Î»ºÅ
   	Box() {}				//¹¹Ôìº¯Êı
   	Box(int i1,int j1,int d1):
		i(i1),j(j1),di(d1) {}  		//ÖØÔØ¹¹Ôìº¯Êı
};

bool mgpath(int xi, int yi, int xe, int ye);
void disppath(stack<Box> &st);

int main(){  
	int xi = 0, yi = 0, xe = 3, ye = 3;
   	printf("Çó(%d,%d)µ½(%d,%d)µÄÃÔ¹¬Â·¾¶\n", xi, yi, xe, ye);
   	if (!mgpath(xi, yi, xe, ye))
    	cout << "²»´æÔÚÃÔ¹¬Â·¾¶\n";
   	return 0;
}

bool mgpath(int xi, int yi, int xe, int ye){	//ÇóÒ»Ìõ´Ó(xi,yi)µ½(xe,ye)µÄÃÔ¹¬Â·¾¶
	int i, j, di, i1, j1;
   	bool find;
   	Box b, b1;
   	stack<Box> st;			//½¨Á¢Ò»¸öÕ»
   	b = Box(xi, yi, -1);
   	st.push(b);				//Èë¿Ú·½¿é½øÕ»
   	mg[xi][yi] = -1;			//Îª±ÜÃâÀ´»ØÕÒÏàÁÚ·½¿éÖÃmgÖµÎª-1
	while (!st.empty()){			//Õ»²»¿ÕÊ±Ñ­»
		b = st.top();			//È¡Õ»¶¥·½¿é,³ÆÎªµ±Ç°·½¿é
    	if (b.i == xe && b.j == ye){		//µ½³ö¿Ú,Êä³öÕ»ÖĞËùÓĞ·½¿é¹¹³ÉÒ»ÌõÂ·¾¶
			disppath(st);
         	return true;			//ÕÒµ½Ò»ÌõÂ·¾¶ºó·µ»Øtrue
      	}
		find = false;				//·ñÔò¼ÌĞøÕÒÂ·¾¶
     	di = b.di;
    	while (di < 3 && find == false){		//ÕÒbµÄÒ»¸öÏàÁÚ¿É×ß·½¿é
    		di++;				//ÕÒÏÂÒ»¸ö·½Î»µÄÏàÁÚ·½¿é
        	i = b.i + dx[di];			//ÕÒbµÄdi·½Î»µÄÏàÁÚ·½¿é(i,j)
        	j = b.j + dy[di];
        	if (i >= 0 && i < m && j >= 0 && j < n && mg[i][j] == 0)
            find = true;			//(i,j)·½¿éÓĞĞ§ÇÒ¿É×ß
     	}
     	if (find){				//ÕÒµ½Ò»¸öÏàÁÚ¿É×ß·½¿é(i,j)
			st.top().di = di;			//ĞŞ¸ÄÕ»¶¥·½¿éµÄdiÎªĞÂÖµ
        	b1 = Box(i, j, -1);			//½¨Á¢ÏàÁÚ¿É×ß·½¿é(i,j)µÄ¶ÔÏób1
        	st.push(b1);			//b1½øÕ» 
        	mg[i][j] = -1;			//Îª±ÜÃâÀ´»ØÕÒÏàÁÚ·½¿éÖÃmgÖµÎª-1
     	}
     	else{				//Õ»¶¥·½¿éÃ»ÓĞÕÒµ½ÈÎºÎÏàÁÚ¿É×ß·½¿é
			mg[b.i][b.j] = 0;			//»Ö¸´Õ»¶¥·½¿éµÄÃÔ¹¬Öµ
        	st.pop();			//½«Õ»¶¥·½¿éÍËÕ»
     	}
   }
   	return false;				//Ã»ÓĞÕÒµ½ÃÔ¹¬Â·¾¶,·µ»Øfalse
}

void disppath(stack<Box> &st){		//Êä³öÕ»ÖĞËùÓĞ·½¿é¹¹³ÉÒ»ÌõÃÔ¹¬Â·¾¶
	Box b;
   	vector<Box> apath;			//´æ·ÅÒ»ÌõÃÔ¹¬Â·¾¶
   	while (!st.empty()){			//³öÕ»ËùÓĞµÄ·½¿é
		b = st.top(); st.pop();
      	apath.push_back(b);
   	}
   	reverse(apath.begin(),	apath.end());	//ÄæÖÃapath(Ò²¿ÉÒÔÖ±½Ó·´ÏòÊä³öapath)
   	cout << "Ò»ÌõÃÔ¹¬Â·¾¶: ";
   	for (int i = 0; i < apath.size(); i++)
      cout << "[" << apath[i].i << "," << apath[i].j << "]  "; 
   cout << endl;
}


