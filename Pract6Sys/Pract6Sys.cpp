// Pract6Sys.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

#define Zo ne
#define Snak e

using namespace std;



int main()
{
    setlocale(0, "rus");
    

    cout << "Для начала игры нажмите 'Space'";
    int start = 0;
    do
    {

        start = _getch();
        start = toupper(start);

    } while (start != ' ');

    system("cls");

    int X = 20;
    int Y = 10;

    Snake Game(X, Y);
    Game.StartGame();

   
}
