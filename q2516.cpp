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
  int takeCharacters(string s, int k)
  {
    if (k == 0)
      return 0;
    int n = s.size();
    vector<int> indexes[3], rindexes[3];
    vector<vector<int>> progress[3], rprogress[3];
    int result = n;

    for (int i = 0; i < 3; i++) {
      indexes[i].reserve(k);
      rindexes[i].reserve(k);
      progress[i].reserve(k);
      rprogress[i].reserve(k);
    }

    for (int i = 0; i < n; i++) {
      const char &c = s[i];
      const char chara = c - 'a';
      auto &handle = indexes[chara];

      if (handle.size() < k) {
        handle.push_back(i + 1);
        progress[chara].push_back(vector<int>(3, 0));
        auto &modifying = progress[chara].back();
        for (int j = 0; j < 3; j++) {
          modifying[j] = indexes[j].size();
        }
      }
      if (indexes[0].size() == k && indexes[1].size() == k && indexes[2].size() == k) {
        result = i + 1;
        break;
      }
    }
    if (!all_of(begin(indexes), end(indexes), [=](vector<int> idx) { return idx.size() == k; }))
      return -1;

    for (int i = n - 1; i >= 0; i--) {
      const char &c = s[i];
      const char chara = c - 'a';
      auto &rhandle = rindexes[c - 'a'];
      int run = n - i;
      if (rhandle.size() < k) {
        rhandle.push_back(run);
        rprogress[chara].push_back(vector<int>(3, 0));
        auto &modifying = rprogress[chara].back();
        for (int j = 0; j < 3; j++) {
          modifying[j] = rindexes[j].size();
        }
      }
      if (rindexes[0].size() == k && rindexes[1].size() == k && rindexes[2].size() == k) {
        result = min(result, n - i);
        break;
      }
    }

    for (int c = 0; c < 3; c++) {
      auto &leftP = progress[c];
      // auto &rightP = rprogress[c];
      for (int lefter = 0; lefter < k; lefter++) {
        auto &letters = leftP[lefter];
        int righterTime = 0;
        for (int rc = 0; rc < 3; rc++) {
          int numleft = letters[rc];
          if (numleft == k)
            continue;
          int numRight = k - numleft;
          int rTime = rindexes[rc][numRight - 1];
          righterTime = max(righterTime, rTime);
        }

        int tempResult = indexes[c][lefter] + righterTime;
        if (tempResult < result) {
          result = tempResult;
        }
      }
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "bcca";
  int k = 1;
  auto result = sln.takeCharacters(s, k);
  return 0;
}
