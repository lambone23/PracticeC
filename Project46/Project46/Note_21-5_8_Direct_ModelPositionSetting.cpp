#include <iostream>
using namespace std;

#define EmptyDestination PStage[DirectY][DirectX] == '_'

struct ModelPosition
{
	int Y;
	int X;
};

struct Input
{
	char Model[7];
	char Order[7][7];
};

enum class EDirection
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

void FnPrint(char PStage[5][3])
{
	cout << endl;
	for (int IdxY = 0; IdxY < 5; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cout << PStage[IdxY][IdxX];
		}
		cout << endl;
	}
	cout << endl;
}

void FnChgPos(char PStage[5][3], int Y, int X, int DirectY, int DirectX, char Model)
{
	PStage[Y][X] = '_';
	PStage[DirectY][DirectX] = Model;
}

void FnDoOrder(char PStage[5][3], char* InOrder, int* InY, int* InX, char Model)
{
	bool FlagDoChangePos = 0;

	int Y = *InY;
	int X = *InX;

	int DirectY = 0;
	int DirectX = 0;

	int Direct[4][2]
		= {
			{-1, 0},
			{0, 1},
			{1, 0},
			{0, -1}
	};

	if (strcmp(InOrder, "UP") == 0)
	{
		DirectY = Y + Direct[(int)EDirection::UP][0];
		DirectX = X + Direct[(int)EDirection::UP][1];

		//cout << "(" << Y << "," << X << ") -> (" << DirectY << "," << DirectX << ")" << endl;

		if ((DirectY >= 0) && EmptyDestination)
		{
			--(*InY);
			FlagDoChangePos = 1;
		}

	}
	else if (strcmp(InOrder, "RIGHT") == 0)
	{
		DirectY = Y + Direct[(int)EDirection::RIGHT][0];
		DirectX = X + Direct[(int)EDirection::RIGHT][1];

		//cout << "(" << Y << "," << X << ") -> (" << DirectY << "," << DirectX << ")" << endl;

		if ((DirectX <= 2) && EmptyDestination)
		{
			++(*InX);
			FlagDoChangePos = 1;
		}
	}
	else if (strcmp(InOrder, "DOWN") == 0)
	{
		DirectY = Y + Direct[(int)EDirection::DOWN][0];
		DirectX = X + Direct[(int)EDirection::DOWN][1];

		//cout << "(" << Y << "," << X << ") -> (" << DirectY << "," << DirectX << ")" << endl;

		if ((DirectY <= 4) && EmptyDestination)
		{
			++(*InY);
			FlagDoChangePos = 1;
		}
	}
	else if (strcmp(InOrder, "LEFT") == 0)
	{
		DirectY = Y + Direct[(int)EDirection::LEFT][0];
		DirectX = X + Direct[(int)EDirection::LEFT][1];

		//cout << "(" << Y << "," << X << ") -> (" << DirectY << "," << DirectX << ")" << endl;

		if ((DirectX >= 0) && EmptyDestination)
		{
			--(*InX);
			FlagDoChangePos = 1;
		}
	}

	if (FlagDoChangePos)
	{
		FnChgPos(PStage, Y, X, DirectY, DirectX, Model);
	}

	//FnPrint(PStage);
	//cout << "==============================" << endl;

}//END - void FnDoOrder

int main()
{
	char Stage[5][3]
		= {
			'_', '_', '_',
			'_', '_', '_',
			'A', 'T', 'K',
			'_', '_', '_',
			'_', '_', '_'
	};

	//FnPrint(Stage);

	Input In = {};

	for (int Idx = 0; Idx < 7; Idx++)
	{
		cin >> In.Model[Idx];
		cin >> In.Order[Idx];
	}

	//for (int Idx = 0; Idx < 7; Idx++)
	//{
	//	cout << In.Model[Idx] << " " << In.Order[Idx] << endl;
	//}

	ModelPosition A = {};
	ModelPosition T = {};
	ModelPosition K = {};

	A.Y = 2;
	A.X = 0;

	T.Y = 2;
	T.X = 1;

	K.Y = 2;
	K.X = 2;

	for (int Idx = 0; Idx < 7; Idx++)
	{
		//cout << "==============================" << endl;
		//cout << Idx  << " : " << In.Model[Idx] << " " << In.Order[Idx] << endl;

		if (In.Model[Idx] == 'A')
		{
			FnDoOrder(Stage, In.Order[Idx], &(A.Y), &(A.X), 'A');
		}
		else if (In.Model[Idx] == 'T')
		{
			FnDoOrder(Stage, In.Order[Idx], &(T.Y), &(T.X), 'T');
		}
		else if (In.Model[Idx] == 'K')
		{
			FnDoOrder(Stage, In.Order[Idx], &(K.Y), &(K.X), 'K');
		}
	}

	FnPrint(Stage);

	return 0;
}
