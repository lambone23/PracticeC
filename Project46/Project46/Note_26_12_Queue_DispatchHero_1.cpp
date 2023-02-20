#include <iostream>
using namespace std;

int main()
{
	char HeroList[5] = "BIAH";	// 최초에 큐에 요소 삽입시 사용하기 위한, 히어로 리스트
	int HeroCnt = 4;			// 히어로 인원수

	char DispatchList[4] = {};	// 출력용 배열
	int DispatchListIdx = 0;	// 출력용 배열에 요소를 채우기 위한, 해당배열 전용 인데스

	bool FlagFirst = 1;			// 최초 체크용

	char* ChkList = nullptr;	// 출력용 배열에 값을 넣기위한 연산 확인용 배열
	char* TmpList = nullptr;	// 연산 확인용 배열을 갱신하기 위한 임시 배열

	ChkList = new char[HeroCnt] {};

	int DispatchHeroIdx = -1;	// 연산 완료 후, 연산확인용 배열에서 출력할 히어로의 인덱스

	bool ChkListFull = 0;		// 최초 연산시 사용하기 위한 큐가 모두 채워졌는지 확인용
	int ChkListCnt = 0;			// 최초 연산시 연산확인용 배열에 채운 횟수 확인용

	for (int DispatchOrder = 1; DispatchOrder < 5; DispatchOrder++)
	{// 히어로가 모두 뽑힐 때까지

		DispatchHeroIdx = -1;
		ChkListFull = 0;
		ChkListCnt = 0;

		// cout << "*** DispatchOrder : " << DispatchOrder << endl;

		for (int ChkCnt = 0; ChkCnt < 5; ChkCnt++)
		{// 다섯번의 척척박사 코카콜라

			if (FlagFirst)
			{// 최초 연산시에만

				for (int Idx = 0; Idx < HeroCnt; Idx++)
				{// 체크리스트를 히어로 요소로 채우기

					if (ChkListCnt == HeroCnt)
					{// 체크리스트가 꽉 찼다면, 채우기작업 종료

						ChkListFull = 1;
					}
					else if ((ChkList[Idx] == '\0') && (FlagFirst))
					{// 체크리스트에 아직 채울공간이 남아있다면, 채우기

						ChkList[Idx] = HeroList[Idx];
						ChkListCnt++;

						// cout << "ChkCnt : " << ChkCnt << " # 1 최초(삽입): " << ChkList[Idx] << endl;
						break;
					}
				}
			}

			if ((ChkListFull) || (!FlagFirst))
			{// 최초 연산이 아닌, 체크리스트는 이전 작업 결과에 따라 순번맞춰 이미 채워진 상태

				DispatchHeroIdx++; // 추출할 인덱스를 찾는 과정

				if (DispatchHeroIdx == HeroCnt)
				{
					DispatchHeroIdx = 0;
				}
				// cout << "ChkCnt : " << ChkCnt << " # 2 인덱스찾기: " << DispatchHeroIdx << endl;
			}
		}//END - for (int ChkCnt = 0; ChkCnt < 5; ChkCnt++) // 다섯번의 척척박사 코카콜라

		// cout << "ChkList : ";
		//for (int Idx = 0; Idx < HeroCnt; Idx++)
		//{
			// cout << ChkList[Idx] << " ";
		//}
		// cout << endl;

		// cout << "추출 값의 인덱스 DispatchHeroIdx : " << DispatchHeroIdx << ", ";
		// cout << "추출 실제값 ChkList[DispatchHeroIdx] : " << ChkList[DispatchHeroIdx] << endl;

		DispatchList[DispatchListIdx++] = ChkList[DispatchHeroIdx]; // 추출할 히어로를 추출용 배열에 담기

		TmpList = new char[HeroCnt] {};

		bool FlagFirstTmpListCopy = 1;

		for (int Idx = 0; Idx < HeroCnt; Idx++)
		{// 연산 확인용 배열을 갱신하기 위한 임시 배열 만들기 과정

			if (((DispatchHeroIdx + 1) < HeroCnt) && (FlagFirstTmpListCopy))
			{
				TmpList[Idx] = ChkList[DispatchHeroIdx + 1];
				// cout << "ChkList 다시 만들기위한 임시저장 # 1 : "<< TmpList[Idx] << endl;
				DispatchHeroIdx++;
			}
			else if ((DispatchHeroIdx + 1) == HeroCnt)
			{
				DispatchHeroIdx = 0;
				TmpList[Idx] = ChkList[DispatchHeroIdx++];
				// cout << "ChkList 다시 만들기위한 임시저장 # 2 : " << TmpList[Idx] << endl;

				FlagFirstTmpListCopy = 0;
			}
			else
			{
				TmpList[Idx] = ChkList[DispatchHeroIdx++];
				// cout << "ChkList 다시 만들기위한 임시저장 # 3 : " << TmpList[Idx] << endl;
			}
		}

		HeroCnt--;

		if (DispatchOrder == 4)
		{
			// cout << "종료" << endl;
		}
		else
		{// 다음 작업을 위해 갱신 : 출력용 배열에 값을 넣기위한 연산 확인용 배열

			// cout << "변경된 HeroCnt : " << HeroCnt << endl;
			ChkList = new char[HeroCnt] {};

			// cout << "변경된 ChkList : ";
			for (int Idx = 0; Idx < HeroCnt; Idx++)
			{
				ChkList[Idx] = TmpList[Idx];
				// cout << ChkList[Idx] << " ";
			}
			// cout << endl;
		}

		FlagFirst = 0;

		// cout << "*****************" << endl;
	}

	for (int Idx = 0; Idx < 4; Idx++)
	{
		cout << DispatchList[Idx] << " ";
	}

	delete[] TmpList;
	delete[] ChkList;

	return 0;
}
