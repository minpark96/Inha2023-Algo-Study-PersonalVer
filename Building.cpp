#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int Build(vector<vector<int>>& land, int* bSize)
	{
		int res = 0;

		size_t landWidth = land[0].size();
		size_t landHeight = land.size();
		bool isSquare;

		int minSize = min(bSize[0], bSize[1]) - 1;

		// 가로 세로 동일한지 구분 해야하나?
		if (bSize[0] == bSize[1])
			isSquare = true; // 한번만 체크
		else
			isSquare = false; // 가로세로로 체크 + 세로가로로 체크

		for (int row = 0; row < landHeight - minSize; row++)
		{
			for (int col = 0; col < landWidth - minSize; col++)
			{
				if (land[row][col] == 0)
				{
					if (DFS(land, bSize[0], bSize[1], row, col))
						res++;

					if (!isSquare)
						if (DFS(land, bSize[1], bSize[0], row, col))
							res++;
				}
			}
		}

		return res;
	}

	bool DFS(vector<vector<int>>& land, int Width, int Height, int row, int col)
	{
		// 범위를 넘겼는지 체크
		if (row >= land.size() || col >= land[0].size())
			return false;

		// 못 짓는 구역
		if (land[row][col] == 1)
			return false;

		// 가로부터 증가하면서 다음 구역 체크
		if (Width > 1)
		{
			if (!DFS(land, Width - 1, Height, row, col + 1))
				return false;
		}

		// 세로 다음 구역 체크
		if (Height > 1)
		{
			if (!DFS(land, Width, Height - 1, row + 1, col))
				return false;
		}
		// 조건 통과
		return true;
	}
};

int main()
{
	Solution s;

	vector<vector<int>> v;
	/*v.push_back({ 0, 0 });
	v.push_back({ 0, 1 });
	int bSize[2] = { 1, 2 };*/

	/*v.push_back({ 1, 0, 0 });
	v.push_back({ 0, 0, 0 });
	v.push_back({ 0, 0, 1 });
	int bSize[2] = {2, 2};*/

	v.push_back({ 0, 0, 1, 0 });
	v.push_back({ 0, 0, 0, 1 });
	v.push_back({ 0, 0, 0, 0 });
	v.push_back({ 0, 1, 0, 0 });
	int bSize[2] = { 2, 2 };

	int ans = s.Build(v, bSize);

	cout << "res: " << ans << endl;

	return 0;
}

