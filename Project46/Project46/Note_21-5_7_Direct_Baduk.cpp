#include <iostream>
using namespace std;

enum class EStone
{
	B,
	W,
	N = 9
};

struct Position
{
	int Y;
	int X;
};

void FnPrint(int Board[7][7])
{
	for (int IdxY = 0; IdxY < 7; IdxY++)
	{
		for (int IdxX = 0; IdxX < 7; IdxX++)
		{
			cout << Board[IdxY][IdxX] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int Board[7][7]
		= {
				(int)EStone::N,	(int)EStone::N,	(int)EStone::N,	(int)EStone::N, (int)EStone::N, (int)EStone::N, (int)EStone::N,
				(int)EStone::N,	(int)EStone::N,	(int)EStone::W,	(int)EStone::N,	(int)EStone::W, (int)EStone::N, (int)EStone::N,
				(int)EStone::N,	(int)EStone::W,	(int)EStone::B,	(int)EStone::N,	(int)EStone::B, (int)EStone::W,	(int)EStone::N,
				(int)EStone::N,	(int)EStone::N,	(int)EStone::W,	(int)EStone::B,	(int)EStone::W, (int)EStone::N,	(int)EStone::N,
				(int)EStone::N,	(int)EStone::N,	(int)EStone::B,	(int)EStone::W,	(int)EStone::N, (int)EStone::W,	(int)EStone::N,
				(int)EStone::N,	(int)EStone::W,	(int)EStone::W,	(int)EStone::N,	(int)EStone::N, (int)EStone::N,	(int)EStone::N,
				(int)EStone::N,	(int)EStone::N,	(int)EStone::N,	(int)EStone::N, (int)EStone::N, (int)EStone::N, (int)EStone::N
	};

	//[S] : ������������������������������������������
	//FnPrint(Board);
	//[E] : ������������������������������������������

	Position Pos = {};

	cin >> Pos.Y >> Pos.X;

	int Direct[4][2]
		= {
			{-1, 0},
			{0, 1},
			{+1, 0},
			{0, -1},
	};

	int BlackY = 0;
	int BlackX = 0;

	int CntCatch = 0;
	int CntCatchExpectation = 0;

	for (int i = 0; i < 4; i++)
	{// �Է� ��ǥ�� ��濡 ���Ͽ� ���̷�Ʈ ������� �浹 ���� Ȯ��

		CntCatchExpectation = 0;

		int DirectY = Pos.Y + Direct[i][0];
		int DirectX = Pos.X + Direct[i][1];

		if (// ���̷�Ʈ ���� ��ǥ�� �������� ����� ��쿡 ���� ����ó��
			(DirectY >= 0) && (DirectY <= 6) &&
			(DirectX >= 0) && (DirectX <= 6)
			)
		{

			if (Board[DirectY][DirectX] == (int)EStone::B)
			{// �浹 �߽߰�

				//�������� �浹�� �����Ͽ� ���̷�Ʈ ��� ����
				BlackY = DirectY;
				BlackX = DirectX;

				//[S] : ������������������������������������������
				//cout << "�浹 (������) : (" << BlackY << "," << BlackX << ")" << endl;
				//[E] : ������������������������������������������

				for (int i = 0; i < 4; i++)
				{// �浹 ����, ��濡 ���Ͽ� ���̷�Ʈ ������� �鵹 ���� Ȯ��

					int BlackDirectY = BlackY + Direct[i][0];
					int BlackDirectX = BlackX + Direct[i][1];

					if (// ���̷�Ʈ ���� ��ǥ�� �������� ����� ��쿡 ���� ����ó��
						(BlackDirectY >= 0) && (BlackDirectY <= 6) &&
						(BlackDirectX >= 0) && (BlackDirectX <= 6)
						)
					{

						//[S] : ������������������������������������������
						//cout << "�浹 ���� : (" << BlackDirectY << "," << BlackDirectX << ")" << endl;
						//[E] : ������������������������������������������

						if (Board[BlackDirectY][BlackDirectX] == (int)EStone::W)
						{// �浹�� ��� �� �鵹�� ��츦 ī����
							++CntCatchExpectation;
						}
					}
				}

				if (CntCatchExpectation == 3)
				{
					/*
						���� �鵹�� �Է���ǥ�� �α� ������,
						�浹�� ����� ��� �鵹�� ��츸
						�� �浹�� ��Ƹ����� ���� ī����
					*/

					++CntCatch;
				}
			}//END - if (Board[DirectY][DirectX] == (int)EStone::B)
		}
	}

	//[S] : ������������������������������������������
	//Board[Pos.Y][Pos.X] = (int)EStone::W;
	//FnPrint(Board);
	//[E] : ������������������������������������������

	cout << CntCatch;

	return 0;
}
