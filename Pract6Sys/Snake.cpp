#include "Snake.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>


int width = 70;
int height = 25;


Snake::Snake(int pos1,int pos2)
{
	
	head = new Node(pos1, pos2);

	Node* current = head;

	direction = 2;

	StatusGame = false;

	length = 10;

	for (int i = 1; i < length; i++)
	{
		current->next = new Node(pos1 - 1, pos2);
		current = current->next;
	}
	
	tail = current;

}
Snake::~Snake()
{

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
		newY++;
		break;
	}
	case 4:
	{
		newY--;
		break;
	}

	}

	Node* Nhead=new Node(newX, newY);
	Nhead->next = head;
	head = Nhead;

	if (head->posX == foodX && head->posY == foodY) {
		foodEaten = true;
		Grow(); 
		SpawnF(); 
	}

	if (!foodEaten) {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		delete tail;
		tail = current;
		tail->next = nullptr;
	}
	else {
		foodEaten = false;
	}

}
void Snake::StartGame() {
	StatusGame = false;

	while (!StatusGame) {
		ChangeDirection();

		Moving();

		GameRange();

		if (CheckYourself()) {
			StatusGame = true;
			system("cls");
			std::cout << "длина: " << length << std::endl;
			_getch();
		}

		Sleep(70);
	}
}
void Snake::ChangeDirection()
{
	if (_kbhit()) {
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
}
void Snake::GameRange()
{
	system("cls");

	for (int i = 0; i < width + 2; i++)
		std::cout << "_";
	std::cout << std::endl;
	for (int y = 0; y < height; y++)
	{

		std::cout << "|";

		for (int x = 0; x < width; x++)
		{
			bool isSnake = false;
			bool food = (x == foodX && y == foodY); 

			Node* current = head;
			bool isHead = true;
			while (current != nullptr) {
				if (current->posX == x && current->posY == y) {

						std::cout << "*"; 
					
					isSnake = true;
					break;
				}
				current = current->next;
				isHead = false;
			}

			if (!isSnake) {
				if (food) {
					std::cout << "+";  
				}
				else {
					std::cout << " "; 
				}
			}
		}

		std::cout << "|" << std::endl;
	}

	for (int i = 0; i < width + 2; i++)
		std::cout << "-";
	std::cout << std::endl;

}
bool Snake::CheckYourself()
{
	if (head->posX < 0 || head->posX >= width ||
		head->posY < 0 || head->posY >= height) {
		return true;
	}

	Node* current = head->next;
	while (current != nullptr)
	{
			if (head->posX == current->posX && head->posY == current->posY)
			{
				return true;
			}	
			current=current->next;

	}


	return false;
}

void Snake::SpawnF()
{
		foodX = rand() % width;
		foodY = rand() % height;
	foodEaten = false;
}
void Snake::Grow()
{
	Node* newTail = new Node(tail->posX, tail->posY);
	tail->next = newTail;
	tail = newTail;
	length++;
}