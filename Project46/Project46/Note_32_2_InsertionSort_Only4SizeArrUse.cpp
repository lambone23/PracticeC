/*

입력 예제
6
35
69
73
83
95
99

출력 결과
금99
은95
동83

*/


#include <iostream>
#include <vector>
using namespace std;

void FnPrint(vector<int>& PVect)
{
	for (int i = 0; i < PVect.size(); i++)
	{
		cout << PVect[i] << " ";
	}
	cout << endl;
}

void FnInput1(int* N)
{
	while (true)
	{
		cin >> *N;

		if ((0 <= *N) && (1000 >= *N))
		{
			break;
		}
		else
		{
			cout << "(최대 1,000명)" << endl;
		}
	}
}

void FnInput2(int* PN, vector<int>& PVect)
{
	int In = 0;

	for (int i = 0; i < *PN; i++)
	{
		cin >> In;
		//Vect.insert(Vect.begin() + i, In);
		PVect.push_back(In);
	}
}

int main()
{
	// 입력
	int N = 0;

	FnInput1(&N);

	vector<int> Vect;

	FnInput2(&N, Vect);

	//cout << endl << "Vect.size() : " << Vect.size() << endl;
	//FnPrint(Vect);

	// 처리
	int Cnt = 0;			// 네 칸의 배열만을 사용해서 삽입정렬을 하기 위함
	int CompIdx = 0;		// 삽입정렬 비교대상 Idx
	int SaveCompIdx = 0;	// 삽입정렬 비교대상 Idx를 연산처리시 값을 넘겨받기 위함
	bool FlagSwap = 0;		// 삽입정렬 Swap 발생 유무 확인용

	for (int i = 1; i < Vect.size(); i++)
	{
		int TmpIdx = i;		// 삽입정렬 기준 Idx
		CompIdx = i - 1;

		Cnt = 3;
		FlagSwap = 0;

		while (CompIdx >= 0)
		{
			SaveCompIdx = CompIdx;

			if (Vect[SaveCompIdx] < Vect[TmpIdx])
			{
				int TmpNumb = Vect[SaveCompIdx];
				Vect[SaveCompIdx] = Vect[TmpIdx];
				Vect[TmpIdx] = TmpNumb;

				TmpIdx = SaveCompIdx;
				FlagSwap = 1;
			}

			--CompIdx;
			--Cnt;

			if ((Cnt == 0) && (FlagSwap != 1))
			{	// 4칸 그 이상의 비교 처리가 더이상 필요하지 않은 경우, 
				// 내림차순 정렬 중 이미 기준값이 최소인 경우
				break;
			}

			if ((Cnt == 0) && (FlagSwap != 0))
			{	// 4칸 그 이상의 비교 처리가 더 필요한 경우, 
				// 다시 4칸 동안을 비교하기 위함
				SaveCompIdx = CompIdx;
				Cnt = 3;
			}
		}
	}

	// 출력
	//FnPrint(Vect);
	cout << "금" << Vect[0] << endl;
	cout << "은" << Vect[1] << endl;
	cout << "동" << Vect[2] << endl;

	// 종료 전 작업
	Vect.clear();

	return 0;
}