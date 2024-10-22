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
  int countCompleteDayPairs(vector<int> &hours)
  {
    auto n = hours.size();
    vector<size_t> modded(24, 0);
    int result = 0;
    for (size_t i = 0; i < n; i++) {
      auto element = hours[i];
      size_t togo = element % 24;
      result += modded[(24 - togo) % 24];
      modded[togo]++;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
