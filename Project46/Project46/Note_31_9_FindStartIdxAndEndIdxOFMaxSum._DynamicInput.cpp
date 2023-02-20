/*

입력 예제
14
1 2 3 2 -3 0 1 -8 3 2 3 -1 2 -3


출력 결과
8 12

*/


#include <iostream>
using namespace std;

struct MaxInfo
{
	int Value;
	int Idx;
	int Size;
};

int *Buildings = nullptr;
MaxInfo** MaxArr = nullptr;

int main()
{
	// 입력
	int n = 0;

	cin >> n;

	Buildings = new int[n];

	for (int Idx = 0; Idx < n; Idx++)
	{
		cin >> Buildings[Idx];
	}

	// 처리
	MaxArr = new MaxInfo * [n] {};

	for (int Idx = 0; Idx < n; Idx++)
	{
		MaxArr[Idx] = new MaxInfo[3] {};
	}

	for (int Size = 1; Size <= n; Size++)
	{
		//cout << "* Size : " << Size << endl;

		{
			int Limit = n - Size + 1;
			
			for (int Idx = 0; Idx < Limit; Idx++)
			{
				int Sum = 0;

				for (int i = Idx; i < Idx + Size; i++)
				{
					Sum += Buildings[i];
				}
				//cout << "##" << endl;
				//cout << "Idx : " << Idx << endl;
				//cout << "Sum : " << Sum << endl;

				if ((MaxArr[Size - 1]->Value) < Sum)
				{
					MaxArr[Size - 1]->Value = Sum;
					MaxArr[Size - 1]->Idx = Idx;
					MaxArr[Size - 1]->Size = Size;
				}
			}
		}
		//cout << "-----------------------" << endl;
		//cout << "* MaxValue : " << MaxArr[Size - 1]->Value << endl;
		//cout << "* MaxIdx : " << MaxArr[Size - 1]->Idx << endl;
		//cout << "========================" << endl;
	}

	//cout << endl << endl;
	//for (int Idx = 0; Idx < n; Idx++)
	//{
	//	cout << "Value : " << MaxArr[Idx]->Value << endl;
	//	cout << "Idx : " << MaxArr[Idx]->Idx << endl;
	//	cout << "Size : " << MaxArr[Idx]->Size << endl;
	//	cout << "-----------------------" << endl;
	//}
	//cout << endl << endl;

	int Max = 0;
	int StarIdx = 0;
	int EndIdx = 0;

	for (int Idx = 0; Idx < n; Idx++)
	{
		if (MaxArr[Idx]->Value > Max)
		{
			Max = MaxArr[Idx]->Value;
			StarIdx = MaxArr[Idx]->Idx;
			EndIdx = StarIdx + (MaxArr[Idx]->Size) - 1;
		}
	}

	cout << StarIdx << " " << EndIdx;

	// 종료 전 동적할당 해제
	for (int Idx = 0; Idx < n; Idx++)
	{
		delete[] MaxArr[Idx];
	}

	delete[] MaxArr;
	delete[] Buildings;

	return 0;
}
