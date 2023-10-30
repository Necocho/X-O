#include <iostream>
using namespace std;

int main()
{
	char field[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}}; 
	// x
	// & 
	// o

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}

	return 0;
}