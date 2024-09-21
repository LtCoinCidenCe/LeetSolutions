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
  int findJudge(int n, vector<vector<int>> &trust)
  {
    int trustCount = trust.size();

    vector<int> judgeList(n + 1, 0);
    vector<int> starList(n + 1, 0);
    for (int i = 0; i < trustCount; i++) {
      const auto &towards = trust[i];
      const auto &subject = towards[0];
      const auto &object = towards[1];
      judgeList[subject]++;
      starList[object]++;
    }

    int candidate = -1;
    for (int i = 1; i < n + 1; i++) {
      if (judgeList[i] == 0 && starList[i] == n - 1) {
        if (candidate == -1) {
          candidate = i;
        }
        else {
          return -1;
        }
      }
    }

    return candidate;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
