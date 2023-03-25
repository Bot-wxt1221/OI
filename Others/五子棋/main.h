#ifndef MAIN_H
#define MAIN_H

#include<math.h>
#include<stdio.h>

/******************棋盘大小*****************/
#define N 19
/******************结构体*****************/
int pieces[N][N]={0};//1为A子，2为B子
int flag=1;//1为A下子，2为B下子


struct zuobiao
{
    int x[N];
    int y[N];
}weizhi[N*N];

#endif