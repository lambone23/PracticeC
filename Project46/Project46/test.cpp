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

vector<Crops> g_VtCrops; // 입력값 - 작물
vector<int> g_VtIntWind; // 입력값 - 강풍

int main()
{
	//===================================
	// 입력
	//===================================

	int N = 0; // 입력 좌표 수

	cin >> N;

	g_VtCrops.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> g_VtCrops[i].Y;
		cin >> g_VtCrops[i].X;
		cin >> g_VtCrops[i].Data;
	}

	int K = 0; // 강풍 횟수

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int InValue = 0;
		cin >> InValue;
		g_VtIntWind.push_back(InValue);
	}

	// 입력값 확인
	//cout << endl << "작물정보" << endl;
	//cout << g_VtCrops.size() << "개" << endl;
	//for (int Idx = 0; Idx < g_VtCrops.size(); Idx++)
	//{
	//	cout << g_VtCrops[Idx].Y << " "
	//		<< g_VtCrops[Idx].X << " "
	//		<< g_VtCrops[Idx].Data << endl;
	//}
	//cout << "----------------" << endl;
	//cout << "강풍 정보" << endl;
	//cout << g_VtIntWind.size() << "번 : ";
	//for (int Idx = 0; Idx < g_VtIntWind.size(); Idx++)
	//{
	//	cout << g_VtIntWind[Idx] << " ";
	//}
	//cout << endl << endl;

	//===================================
	// 처리
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
	// 출력
	//===================================

	cout << Cnt;

	return 0;
}