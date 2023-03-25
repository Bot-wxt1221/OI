/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 08:51:02
 * @LastEditTime: 2022-01-19 09:07:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main()
{
    char ch;
    while(~scanf("%c",&ch)){//用scanf读单个字符
        if(ch>='A'&&ch<='Z'){//大写字符处理
            if(ch+1>'Z'){//越界处理
                printf("%c",'A');
            }else{//不越界
                printf("%c",ch+1);
            }
        }else if(ch>='a'&&ch<='z'){//小写字符处理
            if(ch+1>'z'){//越界处理
                printf("%c",'a');
            }else{//不越界
                printf("%c",ch+1);
            }
        }else if(ch == ' ' || ch == '\n'){//其他字符照搬
            printf("%c",ch);
        }else{
            printf("%c",ch+1);
        }
    }

    return 0;
}
