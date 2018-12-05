#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <conio.h>

#define head 'H'
#define body 'X'
#define blank_char ' '
struct SNAKE //�����ߵ�λ�úͳ��� 
{
    int x[100];
    int y[100];
    int lenth ;
}snake; 

int run = 1; 
char ch;

char map[10][11] = //��ӡ��ͼ 
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
    system("cls");//ÿ����һ��ˢ��һ���ͼ 
    for ( i=0; i<10; i++ ) {//��ӡ��ͼ 
        printf("%s\n", map[i]);
    }
}

void GameOver () //��ʧ�����˳� 
{
    run = 0;
    printf("GAME OVER!\n");
} 

void in() //��ʼ������һ��ʼ���߶��� 
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

void move ()//�ƶ� 
{
    int i = 0;
    ch = _getch();//��ȡ�ַ� 
    map[snake.y[snake.lenth-1]][snake.x[snake.lenth-1]] = blank_char;//�ƶ����Ǹ��ַ���Ϊ�ո� 
    map[snake.y[0]][snake.x[0]] = body;//�ƶ���ͷ����Ϊ���� 
    for( i=snake.lenth-1; i; i-- )
    {
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];
    }  
    switch(ch) //���� 
    {
        case 'w': snake.y[0]--; break;
        case 'a': snake.x[0]--; break;
        case 's': snake.y[0]++; break;
        case 'd': snake.x[0]++; break;
    }
    if(map[snake.y[0]][snake.x[0]] != blank_char ) GameOver();//�Ե��Լ���ײǽ 
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
