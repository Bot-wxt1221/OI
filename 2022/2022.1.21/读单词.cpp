#include <cstring>
#include <cstdio>
 
int main () {
   char str[80] = "This is - www.runoob.com - website";
   const char s[2] = "-";
   char *token;
   
   /* ��ȡ��һ�����ַ��� */
   token = strtok(str, s);
   
   /* ������ȡ���������ַ��� */
   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}
