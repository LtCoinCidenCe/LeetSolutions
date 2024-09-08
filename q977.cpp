#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    int p2 = ranges::lower_bound(nums, 0) - nums.begin();
    int p1 = p2 - 1;

    vector<int> result;
    int n1 = -1;
    int n2 = -1;
    while (true) {
      if (p1 < 0) {
        for (; p2 < n; p2++) {
          result.push_back(nums[p2] * nums[p2]);
        }
        break;
      }
      if (p2 >= n) {
        for (; p1 >= 0; p1--) {
          result.push_back(nums[p1] * nums[p1]);
        }
        break;
      }
      n1 = n1 == -1 ? nums[p1] * nums[p1] : n1;
      n2 = n2 == -1 ? nums[p2] * nums[p2] : n2;
      if (n1 > n2) {
        result.push_back(n2);
        n2 = -1;
        p2++;
      }
      else {
        result.push_back(n1);
        n1 = -1;
        p1--;
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{-4, -1, 0, 3, 10};
  auto result = sln.sortedSquares(nums);
  return 0;
}