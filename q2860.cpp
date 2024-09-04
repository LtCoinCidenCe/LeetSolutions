#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int countWays(vector<int> &nums)
  {
    int n = nums.size();
    ranges::sort(nums);
    int result = nums[0] > 0 ? 1 : 0;

    for (int selectCount = 1; selectCount < n; selectCount++) {
      // selected happy
      int &dividing = nums[selectCount - 1];
      if (selectCount <= dividing) {
        continue;
      }
      if (selectCount >= nums[selectCount]) {
        continue;
      }
      result++;
    }
    result += n > nums[n - 1] ? 1 : 0;
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{0, 0, 0, 0, 7, 7, 7, 7};
  int result = sln.countWays(nums);
  return 0;
}