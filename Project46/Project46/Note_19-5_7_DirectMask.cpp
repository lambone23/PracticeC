#include <iostream>
using namespace std;

void FnInputBitarray(int Pbitarray[2][2])
{
	while (true)
	{
		bool FlagError = 1;

		for (int IdxY = 0; IdxY < 2; IdxY++)
		{
			for (int IdxX = 0; IdxX < 2; IdxX++)
			{
				cin >> Pbitarray[IdxY][IdxX];

				if (Pbitarray[IdxY][IdxX] == 1)
				{
					FlagError = 0;
				}
			}
		}

		if (FlagError)
		{
			cout << "bitarray 입력값이 잘못되었습니다." << endl;
		}
		else
		{
			break;
		}
	}
}//END - void FnInputBitarray

int main()
{

	int map[3][3]
		= {
			3,5,1,
			3,8,1,
			1,1,5
	};

	int bitarray[2][2] = {};

	FnInputBitarray(bitarray);

	/*

		[Y][X]		[Y][X+1]
		[Y+1][X]	[Y+1][X+1]

	*/

	int Direct[4][2]
		= {
			{0, 0}, {0, 1},
			{1, 0}, {1, 1}
	};


	int Sum = 0;
	int MaxSum = 0;
	int MaxSumY = 0;
	int MaxSumX = 0;

	for (int IdxY = 0; IdxY < 2; IdxY++)
	{// map - Y
		for (int IdxX = 0; IdxX < 2; IdxX++)
		{// map - X

			// 패턴 찾기 (다이렉트 기법 적용)

			//cout << "===================================" << endl;
			//cout << "* Idx		: (" << IdxY << "," << IdxX << ")" << endl;
			//cout << "* 기준점	: " << map[IdxY][IdxX] << endl;
			//cout << "===================================" << endl;

			Sum = 0;

			for (int i = 0; i < 4; i++)
			{
				int bitY = Direct[i][0];
				int bitX = Direct[i][1];

				int DirectY = IdxY + Direct[i][0];
				int DirectX = IdxX + Direct[i][1];

				if (1 == bitarray[bitY][bitX])
				{
					//cout << "* 마스킹 map값 : " << map[DirectY][DirectX] << endl;
					Sum += map[DirectY][DirectX];
				}

			}

			if (MaxSum < Sum)
			{
				MaxSum = Sum;
				MaxSumY = IdxY;
				MaxSumX = IdxX;
			}

			//cout << "* Sum : " << Sum << endl;
			//cout << "* MaxSum : " << MaxSum << endl;

		}//END - for (int IdxX = 0; IdxX < 2; IdxX++)
	}//END - for (int IdxY = 0; IdxY < 2; IdxY++)


	cout << "(" << MaxSumY << "," << MaxSumX << ")";

	return 0;
}