#include <iostream>
using namespace std;

int main()
{
	char Str[16] = {};
	int NumbArr[16] = {};
	int NumbArridx = 0;

	cin >> Str;

	for (int Idx = 0; Idx < strnlen_s(Str, sizeof(Str)); Idx++)
	{
		if (('0' <= Str[Idx]) && ('9' >= Str[Idx]))
		{
			NumbArr[NumbArridx++] = (Str[Idx] - '0');
		}
	}

	int LengthNumbArr = 0;

	for (int Idx = 0; Idx < 15; Idx++)
	{
		if (NumbArr[Idx] != '\0')
		{
			++LengthNumbArr;
		}
	}

	//LenthNumbArr * 10
	int Sum = 0;
	int LimitRepeatCnt = LengthNumbArr - 1;

	for (int Idx = 0; Idx < LengthNumbArr; Idx++)
	{
		if (LengthNumbArr >= 1)
		{
			for (int RepeatCnt = 0; RepeatCnt < LimitRepeatCnt; RepeatCnt++)
			{
				NumbArr[Idx] = NumbArr[Idx] * 10;
			}

			--LimitRepeatCnt;
		}

		Sum += NumbArr[Idx];
	}

	cout << Sum + 5 << endl;

	return 0;
}
