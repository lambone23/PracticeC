#include <iostream>
using namespace std;

enum class EFlagPrint
{
	PrintNo,
	PrintYes
};

struct Hero
{
	char Name = ' ';
	Hero* PrevHero = nullptr;
	Hero* NextHero = nullptr;
};

Hero* g_FirstHero = nullptr;
Hero* g_LastHero = nullptr;

void Enqueue(char InName)
{
	if (g_FirstHero == nullptr)
	{
		Hero* DispatchHero = new Hero;
		DispatchHero->Name = InName;
		DispatchHero->PrevHero = nullptr;
		DispatchHero->NextHero = nullptr;

		g_FirstHero = DispatchHero;
		g_LastHero = DispatchHero;
	}
	else
	{
		Hero* ExistedLastHero = g_LastHero;
		ExistedLastHero->NextHero = new Hero;
		ExistedLastHero->NextHero->Name = InName;
		ExistedLastHero->NextHero->PrevHero = ExistedLastHero;
		ExistedLastHero->NextHero->NextHero = nullptr;

		g_LastHero = ExistedLastHero->NextHero;
	}
}

char Dequeue(EFlagPrint FlagPrint)
{
	Hero* ExistedFirstHero = g_FirstHero;
	char ReturnName = ExistedFirstHero->Name;

	if (ExistedFirstHero->NextHero == nullptr)
	{
		delete g_FirstHero;
		g_FirstHero = nullptr;
		g_LastHero = nullptr;
	}
	else
	{
		g_FirstHero = ExistedFirstHero->NextHero;
		g_FirstHero->PrevHero = nullptr;
		ExistedFirstHero->NextHero = nullptr;

		delete ExistedFirstHero;
		ExistedFirstHero = nullptr;
	}

	if (FlagPrint == (EFlagPrint::PrintYes))
	{
		cout << ReturnName << " ";
	}

	return ReturnName;
}

void FnDeleteHero_complete()
{
	Hero* TmpLastHero = g_LastHero;

	while (TmpLastHero != nullptr)
	{
		Hero* DeleteHero = TmpLastHero;
		TmpLastHero = DeleteHero->PrevHero;

		delete DeleteHero;
		DeleteHero = nullptr;
	}
}

int main()
{
	string StrHeroList = "BIAH";

	for (int Idx = 0; Idx < StrHeroList.length(); Idx++)
	{
		Enqueue(StrHeroList[Idx]);
	}

	char TmpHeroName = ' ';

	for (int RepeatCnt1 = 0; RepeatCnt1 < 4; RepeatCnt1++)
	{
		for (int RepeatCnt2 = 0; RepeatCnt2 < 4; RepeatCnt2++)
		{
			TmpHeroName = Dequeue(EFlagPrint::PrintNo);
			Enqueue(TmpHeroName);
		}

		Dequeue(EFlagPrint::PrintYes);
	}

	FnDeleteHero_complete();

	return 0;
}
