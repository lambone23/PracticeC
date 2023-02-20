// 26_Graph.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int values[5] = { 1,3,4,7,9 };
int path[10] = {};
int visited[10] = {};


void run(int level)
{
	if (level == 5)
	{
		return;
	}

	//

	for (size_t i = 0; i < 5; i++)
	{
		if (path[i] == 0)
			continue;

		std::cout << path[i];
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 5; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			path[level] = values[i];
			run(level + 1);
			path[level] = 0;
			visited[i] = 0;
		}
	}
}


int main()
{
	visited[0] = 1;
	run(0);


	return 0;
}
