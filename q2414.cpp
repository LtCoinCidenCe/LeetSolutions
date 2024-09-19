#include <algorithm>
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
  int longestContinuousSubstring(string s)
  {
    int n = s.size();
    int streak = 1;
    int result = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i - 1] + 1) {
        streak++;
      }
      else {
        if (streak > result) {
          result = streak;
        }
        streak = 1;
      }
    }
    if (streak > result) {
      result = streak;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
