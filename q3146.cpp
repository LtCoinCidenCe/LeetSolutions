#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int findPermutationDifference(string s, string t)
  {
    int result = 0;
    vector<int> where(26, -1);
    for (int i = 0; i < s.size(); i++) {
      const char &c = s[i];
      where[int(c - 'a')] = i;
    }
    for (int i = 0; i < t.size(); i++) {
      const char &c = t[i];
      result += abs(where[int(c - 'a')] - i);
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "abcde", t = "edbac";
  int result = sln.findPermutationDifference(s, t);
  return 0;
}