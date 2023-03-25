#include <stdio.h>
 
#define MAXN 20005
 
char sgn[MAXN] = {0};
double ans[MAXN] = {0};
double tot = 0;
int news = 0;
int newa = 0;
 
int main()
{
//	freopen("areas.in","r",stdin);
//	freopen("2.out","w",stdout);
    int h = 0;
    char t = getchar();
    while (t == '/' || t == '\\' || t == '_')
    {
        sgn[++news] = t;
        t = getchar();
    }
    int i = 1;
    while (i <= news)
    {
        double sum = .5, hi = 1;
        if (sgn[i] != '\\')
        {
            ++i;
            continue;
        }
        int st = 1;
        int j;
        for (j = i + 1; j <= news && st > 0; ++j)
        {
            if (sgn[j] == '\\')
            {
                ++st;
                ++hi;
                sum += (hi - .5);
            } else if (sgn[j] == '/')
            {
                --st;
                --hi;
                sum += (hi + .5);
            } else
            {
                sum += hi;
            }
        }
        if (st == 0)
        {
            i = j;
            ans[++newa] = sum;
            tot += sum;
        } else
        {
            ++i;
        }
    }
 
    printf("%.0lf\n%d ", tot, newa);
    for (int i = 1; i <= newa; ++i)
    {
        printf("%.0lf ", ans[i]);
    }
    return 0;
}