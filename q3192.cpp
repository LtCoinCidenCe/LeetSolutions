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
    bool flipped = false;
    int result = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      bool value = flipped ? !nums[i] : nums[i];
      if (!value) {
        result++;
        flipped = !flipped;
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{0, 1, 1, 1, 0, 0};
  auto result = sln.minOperations(nums);
  return 0;
}
