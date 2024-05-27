#include<vector>
#include<algorithm>
#include<ranges>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        int min1=nums[0], max1=nums[0];
        int minIndex = 0, maxIndex = 0;
        for (int j = indexDifference; j < n; j++)
        {
            int i = j - indexDifference;
            if (nums[i] < min1)
            {
                min1 = nums[i];
                minIndex = i;
            }
            if (nums[i]>max1)
            {
                max1 = nums[i];
                maxIndex = i;
            }
            if (abs(nums[j] - min1) >= valueDifference)
            {
                return vector<int>{minIndex, j};
            }
            if (abs(nums[j] - max1) >= valueDifference)
            {
                return vector<int>{maxIndex, j};
            }
        }
        return vector<int>{-1, -1};
    }
};

int q2903()
{
    Solution s;
    vector<int>nums{ 3,2,1 };
    int indexDifference = 2, valueDifference = 4;
    vector<int>result;
    result = s.findIndices(nums, indexDifference, valueDifference);
    return 0;
}
