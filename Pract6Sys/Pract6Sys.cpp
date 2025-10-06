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
#ifndef Zone & Snake


    cout << "Для начала игры нажмите 'Space'";
    int start = 0;
    do
    {

        start = _getch();
        start = toupper(start);

    } while (start != ' ');

    system("cls");

#endif // !Zone & !Snake

    int X = 20;
    int Y = 20;

    Snake Game(X, Y);
    

#ifdef Zone & Snake
#ifdef Zone
    Game.GameRange();
    std::cout << std::endl;
    std::cout << "Тест границ работает или нет";
#endif // Zone
#ifdef Snake
    //чето будет
#endif // Snake


#else
    
    Game.StartGame();

    Game.GameRange();

    bool GameStatus = true;
    while (GameStatus)
    {
        Game.Moving();
        Game.ChangeDirection();
        Sleep(600);
    }
#endif // DEBUG

}





















    //{
    //    char ch;
    //
    //    _cputs("Type 'Y' when finished typing keys: ");
    //    //do
    //    //{
    //        ch = _getch();
    //        ch = toupper(ch);
    // /*   } while (ch != 'Y');*/
    //
    //    cout<<(ch);
    //    _putch('\r');    // Carriage return
    //    _putch('\n');    // Line feed
    //}

        //    /* Display message until key is pressed. */
        //    while (!_kbhit())
        //        std::cout<<("Hit me!! ");

        //    /* Use _getch to throw key away. */
        //    printf("\nKey struck was '%c'\n", _getch());


    // Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
    // Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

    // Советы по началу работы 
    //   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
    //   2. В окне Team Explorer можно подключиться к системе управления версиями.
    //   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
    //   4. В окне "Список ошибок" можно просматривать ошибки.
    //   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
    //   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
