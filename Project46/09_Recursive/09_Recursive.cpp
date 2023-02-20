// 09_Recursive.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 재귀함수
// 나 자신을 호출하는 함수

void run(int level)
{
	if (level == 5)
	{
		return;
	}

	std::cout << "Enter " << level << "\n";

	for (size_t i = 0; i < 4; i++)
	{
		run(level + 1);
	}
	//run(level + 1);
	//run(level + 1);
	//run(level + 1);


	std::cout << "Exit " << level << "\n";
}

int main()
{
	run(0);

	return 0;
}

