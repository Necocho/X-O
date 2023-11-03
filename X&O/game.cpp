#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

int main()
{
	srand(time(NULL));
	char field[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}; 
	int x, y, h = 0;

	// X
	// & 
	// O

	bool PlayerWin = false, AIWin = false, Draw = false;

	do {
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << field[i][j];
			}
			cout << endl;
		}

		cout << "ChoosePos: ";
		cin >> x >> y;
		field[x-1][y-1]='X';
		h++;



		if (h!=9)
		{
		do 
		{
		x = rand() % 3; //0-2
		y = rand() % 3;
		} while (field[x][y] != '.');
		field[x][y] = 'O';
		h++;
		}


		//Игрок
		if (field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X' ||
			field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X' || //по горизонтали
			field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X' ||

			field[0][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X' ||
			field[1][0] == 'X' && field[1][1] == 'X' && field[1][2] == 'X' || //по вертикали
			field[2][0] == 'X' && field[2][1] == 'X' && field[2][2] == 'X' || 

			field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X' || //по диагонали
			field[2][0] == 'X' && field[0][1] == 'X' && field[0][2] == 'X')
		{
			PlayerWin = true;
		}

		//ИИ
		if (field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O' ||
			field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O' || //по горизонтали
			field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O' ||

			field[0][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O' ||
			field[1][0] == 'O' && field[1][1] == 'O' && field[1][2] == 'O' || //по вертикали
			field[2][0] == 'O' && field[2][1] == 'O' && field[2][2] == 'O' ||

			field[0][0] == 'O' && field[1][1] == 'O' && field[2][2] == 'O' || //по диагонали
			field[2][0] == 'O' && field[0][1] == 'O' && field[0][2] == 'O')
		{
			AIWin = true;
		}

		if (PlayerWin == false && AIWin == false && h == 9)
		{
			Draw = true;
		}

		system("CLS");
		} while (PlayerWin == false && AIWin == false && Draw == false);

	if (PlayerWin == true)
	{
		cout << "You Win!";
	}
	if (AIWin == true)
	{
		cout << "You Lose!";
	}
	if (Draw == true)
	{
		cout << "Try again!";
	}


	return 0;

}