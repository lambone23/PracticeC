/*

�Է� ����
ABABCGKABABC
BTBCKABABCT

��� ���
KABABC

*/



#include <iostream>
using namespace std;

struct StartInfo
{
	int Y;
	int X;
	int Len1;
	int Len2;
};

struct NowInfo
{
	int Y;
	int X;
};

struct MaxInfo
{
	int Len;
	int Y;
	int X;
};

int** g_Array2D = nullptr;

StartInfo g_Start = {};
NowInfo g_Now = {};
MaxInfo g_Max = {};

void FnRecursive(int Level)
{
	if (Level == 1)
	{
		g_Now.Y = g_Start.Y;
		g_Now.X = g_Start.X;
	}

	// �� ������ ������ ���� �ε����� ����
	int DirectY = g_Now.Y + 1;
	int DirectX = g_Now.X + 1;

	if ((g_Start.Len1 > DirectY) && (g_Start.Len2 > DirectX))
	{
		if (g_Array2D[DirectY][DirectX] == 1)
		{// �� ���� ������ ���� ö�ڵ� ���� ���

			g_Now.Y = DirectY;
			g_Now.X = DirectX;

			if ((g_Max.Len) < (Level + 1))
			{
				g_Max.Len = Level + 1;
				g_Max.Y = g_Start.Y;
				g_Max.X = g_Start.X;
			}

			// �� ���� ö�ڵ� ������ Ȯ���ϱ� ���Ͽ�, ��� Ž�� ����.
			FnRecursive(Level + 1);
		}
		else
		{// �� ���� ������ ���� ö�ڰ� ���� ���� ���. ��� Ž�� ����.

			return;
		}
	}
	else
	{
		// �� ���� ������ ���� �ε��� ��, 
		// �ϳ��� �� ������ ���̸� ��� ���, ��� Ž�� ����.

		return;
	}
}

int main()
{
	//==========================================
	// # 1. �Է�
	//==========================================
	char Str1[16] = {};
	char Str2[16] = {};

	cin >> Str1 >> Str2;

	//==========================================
	// # 2. �Է°��� �������ȭ
	//==========================================
	int Len1 = strlen(Str1);
	int Len2 = strlen(Str2);

	// �����Ҵ����� 2D�迭 ����
	g_Array2D = new int* [Len1 + 1];

	for (int Idx = 0; Idx < Len1 + 1; Idx++)
	{
		g_Array2D[Idx] = new int[Len2 + 1];
	}

	// �Է°����� ������� �����
	for (int IdxY = 0; IdxY < Len1; IdxY++)
	{
		for (int IdxX = 0; IdxX < Len2; IdxX++)
		{
			if (Str1[IdxY] == Str2[IdxX])
			{
				g_Array2D[IdxY][IdxX] = 1;
			}
			else
			{
				g_Array2D[IdxY][IdxX] = 0;
			}
		}
	}

	//cout << endl;
	//for (int IdxY = 0; IdxY < Len1; IdxY++)
	//{
	//	for (int IdxX = 0; IdxX < Len2; IdxX++)
	//	{
	//		cout << g_Array2D[IdxY][IdxX] << " ";
	//	}

	//	cout << endl;
	//}
	//cout << endl;

	//==========================================
	// # 3. ó��
	//==========================================

	g_Max.Len = 0;

	for (int IdxY = 0; IdxY < Len1; IdxY++)
	{// g_Array2D -Y
		for (int IdxX = 0; IdxX < Len2; IdxX++)
		{// g_Array2D -X

			if (g_Array2D[IdxY][IdxX] == 1)
			{
				g_Start.Y = IdxY;
				g_Start.X = IdxX;
				g_Start.Len1 = Len1;
				g_Start.Len2 = Len2;

				FnRecursive(1);
			}
		}
	}

	if ((g_Max.Len) != 0)
	{
		// ��� ��� 1
		int Y = g_Max.Y;

		for (int RepeatCnt = 0; RepeatCnt < (g_Max.Len); RepeatCnt++)
		{
			cout << Str1[Y++];
		}

		// ��� ��� 2
		//int X = g_Max.X;

		//for (int RepeatCnt = 0; RepeatCnt < (g_Max.Len); RepeatCnt++)
		//{
		//	cout << Str2[X++];
		//}
	}
	else
	{
		cout << "�Է¹��� �� ������ ��ġ�ϴ� �κ��� ���� ����" << endl;
	}

	//==========================================
	// # 4. ���� �� �����Ҵ� ����
	//==========================================

	for (int Idx = 0; Idx < Len1; Idx++)
	{
		delete[] g_Array2D[Idx];
	}

	delete[] g_Array2D;

	return 0;
}
