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

		// ���� ���� �������� ���� �ؾ��ϳ�?
		if (bSize[0] == bSize[1])
			isSquare = true; // �ѹ��� üũ
		else
			isSquare = false; // ���μ��η� üũ + ���ΰ��η� üũ

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
		// ������ �Ѱ���� üũ
		if (row >= land.size() || col >= land[0].size())
			return false;

		// �� ���� ����
		if (land[row][col] == 1)
			return false;

		// ���κ��� �����ϸ鼭 ���� ���� üũ
		if (Width > 1)
		{
			if (!DFS(land, Width - 1, Height, row, col + 1))
				return false;
		}

		// ���� ���� ���� üũ
		if (Height > 1)
		{
			if (!DFS(land, Width, Height - 1, row + 1, col))
				return false;
		}
		// ���� ���
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

