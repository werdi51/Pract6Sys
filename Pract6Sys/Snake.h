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
	int direction; //1-¬лево 2-¬право 3-¬низ 4-¬верх
	bool StatusGame;
	int length;
	
	int foodX; 
	int foodY;
	bool foodEaten; 


public:
	Snake(int positionX,int PositionY);

	~Snake();

	void GameRange();

	void Moving();

	void StartGame();

	void ChangeDirection();

	bool CheckYourself();

	void SpawnF();  

	void Grow();       
	
};

