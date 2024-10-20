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
  int smallestRangeI(vector<int> &nums, int k)
  {
    size_t n = nums.size();
    int maxNum = nums[0], minNum = nums[0];
    for (size_t i = 1; i < n; i++) {
      int element = nums[i];
      if (element > maxNum)
        maxNum = element;
      if (element < minNum)
        minNum = element;
    }
    return max(maxNum - minNum - k - k, 0);
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
