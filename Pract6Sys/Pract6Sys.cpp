// Pract6Sys.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

#define Zon e
#define Snak e

using namespace std;



int main()
{
    srand(time(NULL));
    setlocale(0, "rus");

#ifdef Zone

#else
    cout << "Для начала игры нажмите 'Space'";
    int start = 0;
    do
    {

        start = _getch();
        start = toupper(start);

    } while (start != ' ');

    system("cls");
#endif // 

    int X = 20;
    int Y = 10;

    Snake Game(X, Y);
#ifdef Zone
    Game.GameRange();
    cout << "проверка поля вообще" << endl;
#else
    Game.StartGame();
#endif 

}

   

