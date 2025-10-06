#pragma once

class Snake
{
private:
	struct Node
	{
		int posX;
		int posY;
		Node* next;
		Node(int smg,int smg2);
	};

	Node* head;
	Node* tail;
	int direction;//1-����� 2-������ 3-���� 4-�����
	


public:
	Snake(int positionX,int PositionY);

	~Snake();

	void GameRange();

	void Moving();

	void StartGame();

	void ChangeDirection();

	
};

