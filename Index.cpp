#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
	vector<int> Sum(vector<int>& nums, int target)
	{
		vector<int> output;
		multimap<int, int> index;
		map<int, int> diff;

		for (int i = 0; i < nums.size(); i++)
		{
			index.insert(pair<int, int>(nums[i], i));
		}

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++)
		{
			diff[target - nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (diff[nums[i]] && diff[nums[i]] != i)
			{
				int num1, num2;
				int idx1, idx2;
				num1 = nums[i];
				num2 = nums[diff[nums[i]]];
				idx1 = index[num1];
				idx2 = index[num2];
				output.push_back(idx1);
				output.push_back(idx2);
				break;
			}
		}

		sort(output.begin(), output.end());

		return output;
	}
};

int main()
{
	Solution s;

	//vector<int> nums{ 2, 15, 11, 7 };
	vector<int> input{ 3, 5, 2, 4, 1 };

	//int target = 9;
	int target = 10;

	cout << "input : [ ";
	for (int num : input)
	{
		cout << num << " ";
	}
	cout << "]" << endl;

	cout << "target : " << target << endl;

	vector<int> output;

	output = s.Sum(input, target);

	cout << "output : [ ";
	for (int num : output)
	{
		cout << num << " ";
	}
	cout << "]" << endl;

	return 0;
}