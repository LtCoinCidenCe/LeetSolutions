#include <vector>
using namespace std;

class Solution {
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size(), m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      int &target = dp[i][0];
      if (target != -1) {
        break;
      }

      int one = nums1[i];
      if (one == nums2[0]) {
        int newValue = 1;
        for (int j = i; j < n; j++) {
          dp[j][0] = newValue;
        }
      }
      else {
        dp[i][0] = 0;
      }
    }

    dp[0][0] = -1;
    int tempOne = nums1[0];
    for (int j = 0; j < m; j++) {
      int &target = dp[0][j];
      if (target != -1) {
        break;
      }

      int two = nums2[j];
      if (tempOne == two) {
        int newValue = 1;
        for (int kk = j; kk < m; kk++) {
          dp[0][kk] = newValue;
        }
      }
      else {
        dp[0][j] = 0;
      }
    }

    for (int i = 1; i < n; i++) {
      int one = nums1[i];
      bool oneUsed = false;
      for (int j = 1; j < m; j++) {
        int &target = dp[i][j];

        int two = nums2[j];
        if (one == two) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    return dp[n - 1][m - 1];
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums1{1, 3, 7, 1, 7, 5}, nums2{1, 9, 2, 5, 1};
  int result = sln.maxUncrossedLines(nums1, nums2);
  return 0;
}