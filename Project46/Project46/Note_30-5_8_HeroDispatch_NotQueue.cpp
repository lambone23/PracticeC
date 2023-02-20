/*

입력 예제
5

출력 결과
B A H I

*/


#include <iostream>
using namespace std;

int main()
{
	char Heros[4] = { 'B','I','A','H' };

	int n = 0;

	cin >> n;

	if (n <= 0)
	{
		cout << "아무도 출동하지 않음" << endl;
	}
	else
	{
	}

	bool Dispath[4] = {};
	int Cnt = 0;

	int Total = 4;
	int Idx = 0;

	while (Total != 0)
	{
		Cnt = 0;

		while (true)
		{
			if (Dispath[Idx] == 0)
			{
				++Idx;
				++Cnt;
			}
			else
			{
				++Idx;
			}

			if (Idx == 4)
			{
				Idx = 0;
			}

			//cout << "Total : "<< Total <<", Cnt :" << Cnt << ", DispathIdx : " << Idx - 1 <<endl;

			if (Cnt == n)
			{
				Idx = Idx - 1;
				if (-1 == Idx)
				{
					Idx = 3;
				}
				break;
			}
		}

		cout << Heros[Idx] << " ";
		Dispath[Idx] = 1;

		--Total;
	}

	return 0;
}