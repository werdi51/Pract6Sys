#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

Snake::Snake(int pos1,int pos2)
{
	
	head = new Node(pos1, pos2);

	Node* current = head;

	direction = 2;

	for (int i = 1; i < 3; i++)
	{
		current->next = new Node(pos1 - 1, pos2);
		current = current->next;
	}
	

}
Snake::~Snake()
{
	while (head) {
		Node* per = head;
		head = head->next;
		delete per;
	}
}
Snake::Node::Node(int posX,int posY) :posX(posX),posY(posY), next(nullptr) {
}
void Snake::Moving()
{
	int newX = head->posX;
	int newY = head->posY;

	switch (direction)
	{
	case 1:
	{
		newX--;
		break;
	}
	case 2:
	{
		newX++;
		break;
	}
	case 3:
	{
		newY--;
		break;
	}
	case 4:
	{
		newY++;
		break;
	}

	}
	Node* Nhead=new Node(newX, newY);
	Nhead->next = head;
	head = Nhead;
}
void Snake::StartGame() {
	int length = 3;
	int X = 4;
	int Y = 1;

	Snake start(X, Y);

	for (int i = 0; i < length; i++)
	{
		std::cout << "*";
	}
}
void Snake::ChangeDirection()
{
	char button;
	button = _getch();
	button = toupper(button);
	switch (button)
	{
	case 'W':
		{
		if (direction != 3)
		{
			direction = 4;
		}
			break;
		}
	case 'A':
	{
		if (direction != 2)
		{
			direction = 1;
		}
		break;
	}
	case 'S':
	{
		if (direction != 4)
		{
			direction = 3;
		}
		break;
	}
	case 'D':
	{
		if (direction != 1)
		{
			direction = 2;
		}
		break;
	}

	}
}
void Snake::GameRange()
{
	system("cls");
	int width = 70;
	int height=25;


		for (int i = 0; i < width+2; i++)
		{
			std::cout << "-";
			/*std::cout << std::endl;*/
		}
		std::cout << std::endl;

		for (int y = 0; y < height; y++)
		{
			std::cout << "|";
			for (int x = 0; x < width; x++)
			{
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}

		for (int i = 0; i < width+2; i++)
		{
			std::cout << "-";
			/*std::cout<< std::endl;*/
		}


}

