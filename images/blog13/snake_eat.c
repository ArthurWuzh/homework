# include <stdio.h>
# include <string.h>
# include <windows.h>
# include <stdlib.h>
# include <conio.h>
# include <time.h>
# include <math.h>

# define MAP_ROW 40
# define MAP_LINE 100
# define LENTH 5
int head_x = MAP_ROW / 2, head_y = MAP_LINE / 2, tail_x, tail_y;
char map[MAP_ROW][MAP_LINE];
int snake[MAP_ROW][MAP_LINE];
char direct = 'a';
int food_x, food_y;


void Run()
{
    switch (direct)
    {
    case 'a':
        gotoxy(head_y, head_x);
        printf("q");
        if (snake[head_x][head_y - 1] == 0)
            snake[head_x][head_y - 1] = snake[head_x][head_y] + 1;
        else
            judgeself = 0;
        head_y--;
        break;
    case 'd':
        gotoxy(head_y, head_x);
        printf("q");
        if (snake[head_x][head_y + 1] == 0)
            snake[head_x][head_y + 1] = snake[head_x][head_y] + 1;
        else
            judgeself = 0;
        head_y++;
        break;
    case 's':
        gotoxy(head_y, head_x);
        printf("q");
        if (snake[head_x + 1][head_y] == 0)
            snake[head_x + 1][head_y] = snake[head_x][head_y] + 1;
        else
            judgeself = 0;
        head_x++;
        break;
    case 'w':
        gotoxy(head_y, head_x);
        printf("q");
        if (snake[head_x - 1][head_y] == 0)
            snake[head_x - 1][head_y] = snake[head_x][head_y] + 1;
        else
            judgeself = 0;
        head_x--;
    }
    gotoxy(head_y, head_x);
    printf("Y");
    if (Judgefood())
    {
        score++;
        Food();
    }
    else
    {
        if (snake[tail_x][tail_y] + 1 == snake[tail_x - 1][tail_y])
        {
            snake[tail_x][tail_y] = 0;
            gotoxy(tail_y, tail_x);
            printf(" ");
            tail_x--;
        }
        else if (snake[tail_x][tail_y] + 1 == snake[tail_x + 1][tail_y])
        {
            snake[tail_x][tail_y] = 0;
            gotoxy(tail_y, tail_x);
            printf(" ");
            tail_x++;
        }
        else if (snake[tail_x][tail_y] + 1 == snake[tail_x][tail_y - 1])
        {
            snake[tail_x][tail_y] = 0;
            gotoxy(tail_y, tail_x);
            printf(" ");
            tail_y--;
        }
        else
        {
            snake[tail_x][tail_y] = 0;
            gotoxy(tail_y, tail_x);
            printf(" ");
            tail_y++;
        }
    }

}
int Judgewall()
{
    if (map[head_x][head_y] == '#')
        return 0;
    return 1;
}
int Judgefood()
{
    if (head_x == food_x&&head_y == food_y)
        return 1;
    return 0;
}

