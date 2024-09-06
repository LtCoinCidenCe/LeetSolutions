#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int maximumLength(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> best(k + 1, 0);
    unordered_map<int, vector<int>> dp;
    for (int i = 0; i < n; i++) {
      const int &nnn = nums[i];
      if (!dp.contains(nnn)) {
        dp[nnn].resize(k + 1, 0);
      }

      for (int kn = k; kn >= 1; kn--) {
        dp[nnn][kn] = dp[nnn][kn] + 1;
        if (best[kn - 1] + 1 > dp[nnn][kn]) {
          dp[nnn][kn] = best[kn - 1] + 1;
        }
        if (dp[nnn][kn] > best[kn]) {
          best[kn] = dp[nnn][kn];
        }
      }

      dp[nnn][0]++;
      if (dp[nnn][0] > best[0])
        best[0] = dp[nnn][0];
    }
    return *ranges::max_element(best);
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{1, 2, 2};
  int result = sln.maximumLength(nums, 1);
  return 0;
}
