#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>hashtable;
		vector<int>result;
		int halfTarget = target / 2;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};


int q1()
{
	vector<int>nums{ 2, 7, 11, 15 };
	int target = 9;
	Solution solution;
	auto result = solution.twoSum(nums, target);
	return 0;
}
