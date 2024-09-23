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
  long long maximumSubsequenceCount(string text, string pattern)
  {
    int n = text.size();
    long long result = 0;
    long long letterA = 0, letterB = 0;
    for (int i = 0; i < n; i++) {
      const char c = text[i];
      if (c == pattern[1]) {
        result += letterA;
        letterB++;
      }
      if (c == pattern[0]) {
        letterA++;
      }
    }
    if (letterA > letterB) {
      result += letterA;
    }
    else {
      result += letterB;
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string text = "aabb", pattern = "ab";
  long long result = sln.maximumSubsequenceCount(text, pattern);
  return 0;
}
