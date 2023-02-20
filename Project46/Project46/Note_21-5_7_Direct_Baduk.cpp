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

	//[S] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//FnPrint(Board);
	//[E] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

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
	{// 입력 좌표의 사방에 대하여 다이렉트 기법으로 흑돌 유무 확인

		CntCatchExpectation = 0;

		int DirectY = Pos.Y + Direct[i][0];
		int DirectX = Pos.X + Direct[i][1];

		if (// 다이렉트 적용 좌표가 게임판을 벗어나는 경우에 대한 예외처리
			(DirectY >= 0) && (DirectY <= 6) &&
			(DirectX >= 0) && (DirectX <= 6)
			)
		{

			if (Board[DirectY][DirectX] == (int)EStone::B)
			{// 흑돌 발견시

				//기준점을 흑돌로 변경하여 다이렉트 기법 적용
				BlackY = DirectY;
				BlackX = DirectX;

				//[S] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
				//cout << "흑돌 (기준점) : (" << BlackY << "," << BlackX << ")" << endl;
				//[E] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

				for (int i = 0; i < 4; i++)
				{// 흑돌 기준, 사방에 대하여 다이렉트 기법으로 백돌 유무 확인

					int BlackDirectY = BlackY + Direct[i][0];
					int BlackDirectX = BlackX + Direct[i][1];

					if (// 다이렉트 적용 좌표가 게임판을 벗어나는 경우에 대한 예외처리
						(BlackDirectY >= 0) && (BlackDirectY <= 6) &&
						(BlackDirectX >= 0) && (BlackDirectX <= 6)
						)
					{

						//[S] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
						//cout << "흑돌 주위 : (" << BlackDirectY << "," << BlackDirectX << ")" << endl;
						//[E] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

						if (Board[BlackDirectY][BlackDirectX] == (int)EStone::W)
						{// 흑돌의 사방 중 백돌의 경우를 카운팅
							++CntCatchExpectation;
						}
					}
				}

				if (CntCatchExpectation == 3)
				{
					/*
						아직 백돌을 입력좌표에 두기 이전에,
						흑돌의 사방이 모두 백돌인 경우만
						그 흑돌이 잡아먹히는 경우로 카운팅
					*/

					++CntCatch;
				}
			}//END - if (Board[DirectY][DirectX] == (int)EStone::B)
		}
	}

	//[S] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■
	//Board[Pos.Y][Pos.X] = (int)EStone::W;
	//FnPrint(Board);
	//[E] : ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■

	cout << CntCatch;

	return 0;
}
