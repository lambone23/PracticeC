/*

입력 예제
_A_
#_D
C_#
#__

출력 결과
__A
#_D
_C#
#__

*/



#include <iostream>
using namespace std;

#define MonName (int)EMonPosArrX::Name
#define MonIdx (int)EMonPosArrX::Idx
#define MonY (int)EMonPosArrX::Y
#define MonX (int)EMonPosArrX::X

struct Pos
{
	int Y;
	int X;
};

enum class EMonPosArrX
{
	Name,
	Idx,
	Y,
	X
};

int main()
{
	// 입력
	char Map[4][3] = {};

	int MonsterInfo[12][4] = {};
	int IdxMon = 0;

	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cin >> Map[IdxY][IdxX];

			if (('A' <= Map[IdxY][IdxX]) && ('Z' >= Map[IdxY][IdxX]))
			{
				MonsterInfo[IdxMon][MonName] = (int)(Map[IdxY][IdxX]);
				MonsterInfo[IdxMon][MonIdx] = IdxMon;
				MonsterInfo[IdxMon][MonY] = IdxY;
				MonsterInfo[IdxMon][MonX] = IdxX;

				IdxMon++;
			}
		}
	}

	// 정렬 - 몬스터정보 배열 오름차순
	int CntMonster = IdxMon;

	int TmpArr[4] = {};

	for (int Idx = 0; Idx < CntMonster - 1; Idx++)
	{
		for (int NextIdx = Idx + 1; NextIdx < CntMonster; NextIdx++)
		{
			if (MonsterInfo[Idx][MonName] > MonsterInfo[NextIdx][MonName])
			{
				for (int i = MonName; i <= MonX; i++)
				{
					TmpArr[i] = MonsterInfo[Idx][i];
					MonsterInfo[Idx][i] = MonsterInfo[NextIdx][i];
					MonsterInfo[NextIdx][i] = TmpArr[i];
				}
			}
		}
	}

	// 확인 - 몬스터정보
	//for (int Idx = 0; Idx < CntMonster; Idx++)
	//{
	//	for (int IdxX = 0; IdxX < 4; IdxX++)
	//	{
	//		cout << MonsterInfo[Idx][IdxX] << " ";
	//	}
	//	cout << endl;
	//}

	// 처리
	int Direct[5][2]
		= {
			{0, 1},
			{1, 0},
			{0, -1},
			{-1, 0},

			{0, 1}
	};

	Pos MonPos = {};

	for (int RepeatCnt = 0; RepeatCnt < 5; RepeatCnt++)
	{// 5회 반복

		for (int Idx = 0; Idx < CntMonster; Idx++)
		{// 몬스터 개체수 만큼, 움직임 수행

			MonPos.Y = MonsterInfo[Idx][MonY];
			MonPos.X = MonsterInfo[Idx][MonX];

			int DirectY = MonPos.Y + Direct[RepeatCnt][0];
			int DirectX = MonPos.X + Direct[RepeatCnt][1];

			if (
				(DirectY >= 0) && (DirectY <= 3) &&
				(DirectX >= 0) && (DirectX <= 2) &&
				(Map[DirectY][DirectX] == '_')
				)
			{
				MonsterInfo[Idx][MonY] = DirectY;
				MonsterInfo[Idx][MonX] = DirectX;

				Map[DirectY][DirectX] = MonsterInfo[Idx][MonName];
				Map[MonPos.Y][MonPos.X] = '_';
			}
		}
	}

	// 출력
	cout << endl;
	for (int IdxY = 0; IdxY < 4; IdxY++)
	{
		for (int IdxX = 0; IdxX < 3; IdxX++)
		{
			cout << Map[IdxY][IdxX];
		}
		cout << endl;
	}

	return 0;
}