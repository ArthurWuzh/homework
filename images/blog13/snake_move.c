#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>

#define head 'H'
#define body 'X'
#define blank_char ' '
struct SNAKE //定义蛇的位置和长度 
{
    int x[100];
    int y[100];
    int lenth ;
}snake; 

int run = 1; 
char ch;

char map[10][11] = //打印地图 
{
    "**********",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "*        *",
    "**********" }; 

void PrintMap () 

{
    int i=0;
    system("cls");//每进行一部刷新一遍地图 
    for ( i=0; i<10; i++ ) {//打印地图 
        printf("%s\n", map[i]);
    }
}

void GameOver () //若失败则退出 
{
    run = 0;
    printf("GAME OVER!\n");
} 

void in() //初始化，把一开始的蛇定好 
{
    snake.y[0] = snake.y[1] = snake.y[2] = snake.y[3] = 1;
    snake.x[0] = 5;
    snake.x[1] = 4;
    snake.x[2] = 3;
    snake.x[3] = 2;
    snake.lenth = 4; 
    map[snake.y[0]][snake.x[0]] = head;
    map[snake.y[1]][snake.x[1]] = body;
    map[snake.y[2]][snake.x[2]] = body;
    map[snake.y[3]][snake.x[3]] = body;
    map[snake.y[4]][snake.x[4]] = body;
    run = 1;
    PrintMap();
}

void move ()//移动 
{
    int i = 0;
    ch = _getch();//读取字符 
    map[snake.y[snake.lenth-1]][snake.x[snake.lenth-1]] = blank_char;//移动后那个字符改为空格 
    map[snake.y[0]][snake.x[0]] = body;//移动后头部改为身体 
    for( i=snake.lenth-1; i; i-- )
    {
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];
    }  
    switch(ch) //方向 
    {
        case 'w': snake.y[0]--; break;
        case 'a': snake.x[0]--; break;
        case 's': snake.y[0]++; break;
        case 'd': snake.x[0]++; break;
    }
    if(map[snake.y[0]][snake.x[0]] != blank_char ) GameOver();//吃到自己或撞墙 
    else map[snake.y[0]][snake.x[0]] = head;
}

int main() 
{
    in() ;
    while (run) 
    {   
        move();
        PrintMap();
    }
    return 0;
}  
