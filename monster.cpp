#include <iostream>

typedef struct vec2D
{
	int x;
	int y;
};

bool CheckBackward(vec2D characterPos, vec2D characterDir, vec2D monsterPos, vec2D monsterDir)
{
	float dotProd = (monsterPos.x - characterPos.x) * characterDir.x + (monsterPos.y - characterPos.y) * characterDir.y;

	if (dotProd < 0) return true;
	else return false;
}



int Func(int A, int B)
{
	int temp;
	while (A > 0)
	{
		if (A < B)
		{
			temp = A;
			A = B;
			B = temp;
		}
		A = A % B;
	}
	return 0;
}
