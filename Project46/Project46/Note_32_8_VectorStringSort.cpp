/*

�Է� ����
5
redeye
apple
Steve
Berry
eUnBo


��� ���
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
		{// �������� �ʽ��ϴ�.
		}
		else if ((int)Case == (int)ECase::Second)
		{// ù ���� �빮��, ������ �ҹ��ڷ�
			Name.front() = toupper(Name.front());
			VtStrNames[i] = Name;
		}
		else if ((int)Case == (int)ECase::Third)
		{// ��� �빮�ڷ�

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
			cout << "���Է�" << endl;
		}
		else
		{
			break;
		}
	}
}//END - void FnInput

int main()
{
	// �Է�
	vector<string> VtStrNames;

	FnInput(VtStrNames);

	// ó��
	FnChg(VtStrNames);
	FnSort(VtStrNames);

	// ���
	FnPrint(VtStrNames);

	// ���� �� �۾�
	VtStrNames.clear();

	return 0;
}