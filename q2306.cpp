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
  long long distinctNames(vector<string> &ideas)
  {
    vector<vector<int>> intersection(26, vector<int>(26, 0));
    int n = ideas.size();
    vector<int> start(26, 0);
    unordered_map<string, vector<int>> taboos;
    for (int i = 0; i < n; i++) {
      const auto &nameIdea = ideas[i];
      int index = nameIdea[0] - 'a';

      start[index]++;
      string identifier = nameIdea.substr(1);
      auto &prefixes = taboos[identifier];
      for (int j = 0; j < prefixes.size(); j++) {
        intersection[prefixes[j]][index]++;
        intersection[index][prefixes[j]]++;
      }
      prefixes.push_back(index);
    }
    long long result = 0;

    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        // for prefixes i and j
        int commonIdentifier = intersection[i][j];
        result += (start[i] - commonIdentifier) * (start[j] - commonIdentifier);
      }
    }

    return result * 2;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<string> text{"aaa", "baa", "caa", "bbb", "cbb", "dbb"};
  auto result = sln.distinctNames(text);
  return 0;
}
