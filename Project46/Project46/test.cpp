#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Crops
{
	int Y;
	int X;
	string Data;
};

vector<Crops> g_VtCrops; // �Է°� - �۹�
vector<int> g_VtIntWind; // �Է°� - ��ǳ

int main()
{
	//===================================
	// �Է�
	//===================================

	int N = 0; // �Է� ��ǥ ��

	cin >> N;

	g_VtCrops.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> g_VtCrops[i].Y;
		cin >> g_VtCrops[i].X;
		cin >> g_VtCrops[i].Data;
	}

	int K = 0; // ��ǳ Ƚ��

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int InValue = 0;
		cin >> InValue;
		g_VtIntWind.push_back(InValue);
	}

	// �Է°� Ȯ��
	//cout << endl << "�۹�����" << endl;
	//cout << g_VtCrops.size() << "��" << endl;
	//for (int Idx = 0; Idx < g_VtCrops.size(); Idx++)
	//{
	//	cout << g_VtCrops[Idx].Y << " "
	//		<< g_VtCrops[Idx].X << " "
	//		<< g_VtCrops[Idx].Data << endl;
	//}
	//cout << "----------------" << endl;
	//cout << "��ǳ ����" << endl;
	//cout << g_VtIntWind.size() << "�� : ";
	//for (int Idx = 0; Idx < g_VtIntWind.size(); Idx++)
	//{
	//	cout << g_VtIntWind[Idx] << " ";
	//}
	//cout << endl << endl;

	//===================================
	// ó��
	//===================================

	for (int Idx = 0; Idx < g_VtIntWind.size(); Idx++)
	{
		int Wind = g_VtIntWind[Idx];

		for (int i = 0; i < g_VtCrops.size(); i++)
		{
			string CropsStr = g_VtCrops[i].Data;
			int CompCrops = CropsStr.back() - '0';

			if (Wind > CompCrops)
			{
				CropsStr.pop_back();

				if (CropsStr.size() == 0)
				{
					g_VtCrops[i].Data = '0';
				}
				else
				{
					g_VtCrops[i].Data = CropsStr;
				}
				
			}
			else
			{
				int LastIdx = CropsStr.size() - 1;
				CropsStr[LastIdx] = CompCrops - Wind + '0';
				g_VtCrops[i].Data = CropsStr;
			}
		}
	}

	int Cnt = 0;

	for (int Idx = 0; Idx < g_VtCrops.size(); Idx++)
	{
		int CompStoI = stoi(g_VtCrops[Idx].Data);
		string StrData = g_VtCrops[Idx].Data;
		
		if (CompStoI != 0)
		{
			if (StrData.size() != 1)
			{
				Cnt += StrData.size();
			}
			else
			{
				++Cnt;
			}
		}
	}

	//===================================
	// ���
	//===================================

	cout << Cnt;

	return 0;
}