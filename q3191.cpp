#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums)
  {
    int n = nums.size();
    int result = 0;
    // 0 1 背包
    // 并且，边界的值具有确定性，是否需要flip
    bool flipped[2]{false, false};
    for (int i = 0; i < n - 2; i++) {
      // int untouched = nums[i];
      bool currentValue = flipped[0] ? !(nums[i]) : nums[i];
      if (currentValue) {
        flipped[0] = flipped[1];
        flipped[1] = false;
      }
      else {
        flipped[0] = !flipped[1];
        flipped[1] = true;
        result += 1;
      }
    }
    bool final1 = flipped[0] ? !(nums[n - 2]) : nums[n - 2];
    bool final2 = flipped[1] ? !(nums[n - 1]) : nums[n - 1];
    if (final1 && final2)
      return result;
    else
      return -1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{0, 1, 1, 1, 0, 0};
  auto result = sln.minOperations(nums);
  return 0;
}
