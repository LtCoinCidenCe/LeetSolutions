#include <algorithm>
#include <functional>
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
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int n = values.size();
    int result = 0;
    int bestOldIndex = 0;
    for (int i = 1; i < n; i++) {
      int num = values[i];
      int oldChamp = values[bestOldIndex] + bestOldIndex - i;

      int tempResult = num + oldChamp;
      if (result < tempResult) {
        result = tempResult;
      }
      if (num > oldChamp) {
        bestOldIndex = i;
      }
    }

    return result;
  }
};

class SolutionOld {
public:
  int maxScoreSightseeingPair(vector<int> &values)
  {
    int n = values.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      int v1 = values[i];
      for (int di = 1; di < n - i; di++) {
        int j = i + di;
        int v2 = values[j];
        result = max(result, v1 + v2 - di);
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
