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
    while(~scanf("%c",&ch)){//��scanf�������ַ�
        if(ch>='A'&&ch<='Z'){//��д�ַ�����
            if(ch+1>'Z'){//Խ�紦��
                printf("%c",'A');
            }else{//��Խ��
                printf("%c",ch+1);
            }
        }else if(ch>='a'&&ch<='z'){//Сд�ַ�����
            if(ch+1>'z'){//Խ�紦��
                printf("%c",'a');
            }else{//��Խ��
                printf("%c",ch+1);
            }
        }else if(ch == ' ' || ch == '\n'){//�����ַ��հ�
            printf("%c",ch);
        }else{
            printf("%c",ch+1);
        }
    }

    return 0;
}
