#include <algorithm>
#include <vector>
using namespace std;

// bloody math proving problem
class Solution {
public:
  int maxNumOfMarkedIndices(vector<int> &nums)
  {
    ranges::sort(nums);
    int i = 0, n = nums.size();
    for (int j = (n + 1) / 2; j < n; j++) {
      if (nums[i] * 2 <= nums[j]) {
        i++;
      }
    }
    return i * 2;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{9, 2, 5, 4};
  int result = sln.maxNumOfMarkedIndices(nums);
  return 0;
}