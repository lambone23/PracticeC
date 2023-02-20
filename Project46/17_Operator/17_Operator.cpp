#include <iostream>



struct Pos
{
	int x;
	int y;
	//int z;
	//int w;

	void operator+=(Pos other)
	{
		x += other.x;
		y += other.y;
		//z += other.z;
		//w += other.w;
	}

	void operator++(void)
	{
		x++;
		y++;
		//z++;
		//w++;
	}

	//+ -*/ = <    > += -= *= /= <<   >>
	//	<<= >>= ==   !=   <=   >=   ++   -- % &^!|
	//	~&= ^= |= && || %= [](), ->*  ->   new
	//	delete    new[]     delete[]
};

//void* operator new (size_t size)
//{
//	void* adr = new char[size];
//	return adr;
//}


class GameObject
{
public:
	GameObject()
		: mPos(Pos{ 0,0 })
	{

	}

	void Move(/*const GameObject* const this*/ Pos pos) const
	{
		//mPos.x += pos.x;
		//mPos.y += pos.y;
		//mPos.z += pos.z;
		//mPos++;

		//this->mPos += pos;
	}

private:
	Pos mPos;
};
int main()
{
	GameObject player;
	GameObject monster;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>

	player.Move(Pos{ 1, 1 });
	monster.Move(Pos{ 2, 2 });

	int d = 20;
	int e = 30;

	const int* p = &d;
	int* const p2 = &d;

	p = &e;
	*p = 200;

	p2 = &e;
	*p2 = 300;

	//void test(char* str);
	//test("SDFSDF");

	return 0;
}


