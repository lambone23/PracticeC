/*

입력 예제
5
redeye
apple
Steve
Berry
eUnBo


출력 결과
Apple
Berry
EUNBO
Redeye
Steve

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

enum class EisAlpha
{
	None,
	Up,
	Low
};

enum class ECase
{
	First,
	Second,
	Third,
	None = 999
};

ECase FnGetCase(string Name)
{
	ECase ReturnValue = ECase::None;

	if (isalpha(Name.front()) == (int)EisAlpha::Up)
	{
		for (int Idx = 1; Idx < Name.size(); Idx++)
		{
			if (isalpha(Name[Idx]) == (int)EisAlpha::Low)
			{
				ReturnValue = ECase::First;
			}
			else
			{
				ReturnValue = ECase::Third;
				break;
			}
		}
	}
	else if (isalpha(Name.front()) == (int)EisAlpha::Low)
	{
		for (int Idx = 1; Idx < Name.size(); Idx++)
		{
			if (isalpha(Name[Idx]) == (int)EisAlpha::Low)
			{
				ReturnValue = ECase::Second;
			}
			else
			{
				ReturnValue = ECase::Third;
				break;
			}
		}
	}

	return ReturnValue;
}//END - ECase FnGetCase

bool FnChkValid(string& Name)
{
	bool ReturnFlag = 0;

	for (int i = 0; i < Name.length(); i++)
	{
		if (isalpha(Name[i]) != (int)EisAlpha::None)
		{
			ReturnFlag = 1;
		}
		else
		{
			ReturnFlag = 0;
			break;
		}
	}

	return ReturnFlag;
}

void FnSort(vector<string>& VtStrNames)
{
	std::sort(VtStrNames.begin(), VtStrNames.end());
}

void FnChg(vector<string>& VtStrNames)
{
	for (int i = 0; i < VtStrNames.size(); i++)
	{
		string Name = VtStrNames[i];
		ECase Case = FnGetCase(Name);

		if ((int)Case == (int)ECase::First)
		{// 변경하지 않습니다.
		}
		else if ((int)Case == (int)ECase::Second)
		{// 첫 글자 대문자, 나머지 소문자로
			Name.front() = toupper(Name.front());
			VtStrNames[i] = Name;
		}
		else if ((int)Case == (int)ECase::Third)
		{// 모두 대문자로

			for (int Idx = 0; Idx < Name.length(); Idx++)
			{
				Name[Idx] = toupper(Name[Idx]);
			}

			VtStrNames[i] = Name;
		}
	}
}

void FnPrint(vector<string>& VtStrNames)
{
	cout << endl;
	for (int i = 0; i < VtStrNames.size(); i++)
	{
		cout << VtStrNames[i] << endl;
	}
}

void FnInput(vector<string>& VtStrNames)
{
	while (true)
	{
		int ResultChkValid = 0;

		int Cnt = 0;

		cin >> Cnt;

		VtStrNames.resize(Cnt);

		for (int i = 0; i < VtStrNames.size(); i++)
		{
			string InStr = "";
			cin >> InStr;

			ResultChkValid = FnChkValid(InStr);

			if (ResultChkValid)
			{
				VtStrNames[i] = InStr;
			}
			else
			{
				break;
			}
		}

		if (!ResultChkValid)
		{
			cout << "재입력" << endl;
		}
		else
		{
			break;
		}
	}
}//END - void FnInput

int main()
{
	// 입력
	vector<string> VtStrNames;

	FnInput(VtStrNames);

	// 처리
	FnChg(VtStrNames);
	FnSort(VtStrNames);

	// 출력
	FnPrint(VtStrNames);

	// 종료 전 작업
	VtStrNames.clear();

	return 0;
}