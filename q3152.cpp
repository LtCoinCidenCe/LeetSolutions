#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    vector<int> traps;
    // vector<bool> special(n, false);
    for (int i = 0; i < n - 1; i++) {
      if (!(bool(nums[i] & 1) ^ bool(nums[i + 1] & 1))) {
        // special[i] = true;
        traps.push_back(i);
      }
    }

    int m = queries.size();
    vector<bool> result(m, true);
    for (int i = 0; i < m; i++) {
      const vector<int> &query = queries[i];
      auto left = ranges::lower_bound(traps, query[0]);
      if (left != traps.end())
        if (*left < query[1]) {
          result[i] = false;
          continue;
        }

      auto right = upper_bound(traps.rbegin(), traps.rend(), query[1], greater());
      if (right != traps.rend())
        if (*right >= query[0]) {
          result[i] = false;
          continue;
        }
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{4, 3, 1, 6};
  vector<vector<int>> queries{{0, 2}, {2, 3}};
  auto result = sln.isArraySpecial(nums, queries);
  return 0;
}