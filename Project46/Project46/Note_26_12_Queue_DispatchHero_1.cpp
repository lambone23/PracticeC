#include <iostream>
using namespace std;

int main()
{
	char HeroList[5] = "BIAH";	// ���ʿ� ť�� ��� ���Խ� ����ϱ� ����, ����� ����Ʈ
	int HeroCnt = 4;			// ����� �ο���

	char DispatchList[4] = {};	// ��¿� �迭
	int DispatchListIdx = 0;	// ��¿� �迭�� ��Ҹ� ä��� ����, �ش�迭 ���� �ε���

	bool FlagFirst = 1;			// ���� üũ��

	char* ChkList = nullptr;	// ��¿� �迭�� ���� �ֱ����� ���� Ȯ�ο� �迭
	char* TmpList = nullptr;	// ���� Ȯ�ο� �迭�� �����ϱ� ���� �ӽ� �迭

	ChkList = new char[HeroCnt] {};

	int DispatchHeroIdx = -1;	// ���� �Ϸ� ��, ����Ȯ�ο� �迭���� ����� ������� �ε���

	bool ChkListFull = 0;		// ���� ����� ����ϱ� ���� ť�� ��� ä�������� Ȯ�ο�
	int ChkListCnt = 0;			// ���� ����� ����Ȯ�ο� �迭�� ä�� Ƚ�� Ȯ�ο�

	for (int DispatchOrder = 1; DispatchOrder < 5; DispatchOrder++)
	{// ����ΰ� ��� ���� ������

		DispatchHeroIdx = -1;
		ChkListFull = 0;
		ChkListCnt = 0;

		// cout << "*** DispatchOrder : " << DispatchOrder << endl;

		for (int ChkCnt = 0; ChkCnt < 5; ChkCnt++)
		{// �ټ����� ôô�ڻ� ��ī�ݶ�

			if (FlagFirst)
			{// ���� ����ÿ���

				for (int Idx = 0; Idx < HeroCnt; Idx++)
				{// üũ����Ʈ�� ����� ��ҷ� ä���

					if (ChkListCnt == HeroCnt)
					{// üũ����Ʈ�� �� á�ٸ�, ä����۾� ����

						ChkListFull = 1;
					}
					else if ((ChkList[Idx] == '\0') && (FlagFirst))
					{// üũ����Ʈ�� ���� ä������� �����ִٸ�, ä���

						ChkList[Idx] = HeroList[Idx];
						ChkListCnt++;

						// cout << "ChkCnt : " << ChkCnt << " # 1 ����(����): " << ChkList[Idx] << endl;
						break;
					}
				}
			}

			if ((ChkListFull) || (!FlagFirst))
			{// ���� ������ �ƴ�, üũ����Ʈ�� ���� �۾� ����� ���� �������� �̹� ä���� ����

				DispatchHeroIdx++; // ������ �ε����� ã�� ����

				if (DispatchHeroIdx == HeroCnt)
				{
					DispatchHeroIdx = 0;
				}
				// cout << "ChkCnt : " << ChkCnt << " # 2 �ε���ã��: " << DispatchHeroIdx << endl;
			}
		}//END - for (int ChkCnt = 0; ChkCnt < 5; ChkCnt++) // �ټ����� ôô�ڻ� ��ī�ݶ�

		// cout << "ChkList : ";
		//for (int Idx = 0; Idx < HeroCnt; Idx++)
		//{
			// cout << ChkList[Idx] << " ";
		//}
		// cout << endl;

		// cout << "���� ���� �ε��� DispatchHeroIdx : " << DispatchHeroIdx << ", ";
		// cout << "���� ������ ChkList[DispatchHeroIdx] : " << ChkList[DispatchHeroIdx] << endl;

		DispatchList[DispatchListIdx++] = ChkList[DispatchHeroIdx]; // ������ ����θ� ����� �迭�� ���

		TmpList = new char[HeroCnt] {};

		bool FlagFirstTmpListCopy = 1;

		for (int Idx = 0; Idx < HeroCnt; Idx++)
		{// ���� Ȯ�ο� �迭�� �����ϱ� ���� �ӽ� �迭 ����� ����

			if (((DispatchHeroIdx + 1) < HeroCnt) && (FlagFirstTmpListCopy))
			{
				TmpList[Idx] = ChkList[DispatchHeroIdx + 1];
				// cout << "ChkList �ٽ� ��������� �ӽ����� # 1 : "<< TmpList[Idx] << endl;
				DispatchHeroIdx++;
			}
			else if ((DispatchHeroIdx + 1) == HeroCnt)
			{
				DispatchHeroIdx = 0;
				TmpList[Idx] = ChkList[DispatchHeroIdx++];
				// cout << "ChkList �ٽ� ��������� �ӽ����� # 2 : " << TmpList[Idx] << endl;

				FlagFirstTmpListCopy = 0;
			}
			else
			{
				TmpList[Idx] = ChkList[DispatchHeroIdx++];
				// cout << "ChkList �ٽ� ��������� �ӽ����� # 3 : " << TmpList[Idx] << endl;
			}
		}

		HeroCnt--;

		if (DispatchOrder == 4)
		{
			// cout << "����" << endl;
		}
		else
		{// ���� �۾��� ���� ���� : ��¿� �迭�� ���� �ֱ����� ���� Ȯ�ο� �迭

			// cout << "����� HeroCnt : " << HeroCnt << endl;
			ChkList = new char[HeroCnt] {};

			// cout << "����� ChkList : ";
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
