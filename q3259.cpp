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
  long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
  {
    size_t n = energyDrinkA.size();
    vector<vector<long long>> dp(2, vector<long long>(n, -1));
    dp[0][0] = energyDrinkA[0];
    dp[0][1] = energyDrinkA[0] + energyDrinkA[1];
    dp[1][0] = energyDrinkB[0];
    dp[1][1] = energyDrinkB[0] + energyDrinkB[1];
    for (size_t i = 2; i < n; i++) {
      for (size_t p = 0; p < 2; p++) {
        int stage = p == 0 ? energyDrinkA[i] : energyDrinkB[i];
        long long follow = dp[p][i - 1];
        long long switching = dp[!p][i - 2];
        dp[p][i] = max(follow, switching) + stage;
      }
    }

    long long result = max(dp[0][n - 1], dp[1][n - 1]);
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
