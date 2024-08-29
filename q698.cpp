#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  int full;
  int n;
  int setsum;
  vector<bool> dp;
  vector<int> *numero;
  bool canP(int s, int bucket)
  {
    if (s == full) {
      return true;
    }
    if (!dp[s]) {
      return false;
    }
    for (int i = 0; i < n; i++) {
      if (numero->at(i) + bucket > setsum) {
        break;
      }
      if (((s >> i) & 1) == 0) {
        // not used
        if (canP(s | (1 << i), bucket + numero->at(i) == setsum ? 0 : bucket + numero->at(i))) {
          return true;
        }
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int> &nums, int k)
  {
    numero = &nums;
    n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
      return false;
    }
    setsum = sum / k;
    ranges::sort(nums);
    full = (1 << n) - 1;
    dp.resize(full + 1, true);
    return canP(0, 0);
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{4, 3, 2, 3, 5, 2, 1};
  int k = 4;
  bool result = sln.canPartitionKSubsets(nums, k);
  return 0;
}
