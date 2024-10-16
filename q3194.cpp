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
  double minimumAverage(vector<int> &nums)
  {
    ranges::sort(nums);
    double a, b, result = INT32_MAX;
    const size_t n = nums.size();

    for (size_t i = 0; i < n / 2; i++) {
      a = nums[i];
      b = nums[n - 1 - i];
      result = min(result, a + b);
    }
    return result / 2;
  }
};

int main(int argc, char **argv)
{
  Solution sln;

  return 0;
}
