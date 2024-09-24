#include <iostream>
#include <windows.h>
#include <conio.h>

// board height and width
const int width = 80;
const int height = 20;

int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;

enum snakeDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

snakesDirection sDir;
bool isGameOver;

void GameInit()
{
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

void GameRender(std::string playerName)
{
    system("cls");

    // top walls "-"
    for (int i = 0; i < width + 2; i++)
        std::cout << "-";
    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == 0 || j == width)
                std::cout << "|";
            if (i == y && j == x)
                std::cout << "O";
            else if (i == fruitCordY && j == fruitCordX)
                std::cout << "#";
            else
            {
                bool printTail = false;
                for (int k = 0; k < snakeTailLen; k++)
                {
                    if (snakeTailX[k] == j && snakeTailY[k] == i)
                    {
                        std::cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    // bottom walls "-"
    for (int i = 0; i < width + 2; i++)
        std::cout << "-";
    std::cout << std::endl;

    std::cout << playerName << "'s score: " << playerScore << std::endl;
}

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;

    for (int i = 1; i < snakeTailLen; i++)
    {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
}