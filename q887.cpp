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
  int superEggDrop(int k, int n)
  {
    if (n == 1)
      return 1;
    if (k == 1)
      return n;
    double twoResult = (-1 + sqrt(1 + 8 * n)) / 2;
    int intTwoResult = ceil(twoResult);
    if (k == 2)
      return intTwoResult;
    intTwoResult++;

    vector<vector<int>> dp(k, vector<int>(intTwoResult, -1));
    for (int i = 0; i < intTwoResult; i++) {
      dp[0][i] = i;
    }
    for (int i = 0; i < k; i++) {
      dp[i][0] = 0;
      dp[i][1] = 1;
    }

    int i, j;
    for (j = 1; j < k; j++) {
      int trueEggNo = j + 1;
      int expnt = 4;

      for (i = 2; i < intTwoResult; i++) {
        int building;
        if (i <= trueEggNo) {
          // exponential phase, too much eggs
          building = expnt - 1;
          if (building >= n) {
            return i;
          }
          expnt += expnt;
        }
        else {
          // common steps available phase, too much steps
          building = dp[j][i - 1] + dp[j - 1][i - 1] + 1;
        }
        dp[j][i] = building;
        if (building >= n) {
          break;
        }
      }
    }

    return i;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  auto result = sln.superEggDrop(3, 14);

  return 0;
}
