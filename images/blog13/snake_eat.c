#define food_char '$'

struct FOOD
{
    int x;
    int y;
}food;

void SpawnFood () 
{
    food.x = rand() % 8 + 1;
    food.y = rand() % 9 + 1; 
    while(map[food.y][food.x] != blank_char) {
        food.x = rand() % 8 + 1;
        food.y = rand() % 9 + 1; 
    }
    map[food.y][food.x] = food_char;
    IsFood = 1;
}

void snakeextent(){
	if(map[snake.y[0]][snake.x[0]] != blank_char && map[snake.y[0]][snake.x[0]] != food_char) GameOver();
    if(map[snake.y[0]][snake.x[0]] == food_char ) 
    {
        map[snake.y[0]][snake.x[0]] = head;
        snake.lenth++;
        IsFood = 0;
    }
    else map[snake.y[0]][snake.x[0]] = head;
} 
int main() 
{
    InitGame() ;
    while (gamerun) 
    {
        srand(time(NULL));
        MoveSnake();
        if(!IsFood) SpawnFood ();
        PrintMap();
    }
    return 0;
}  




    

