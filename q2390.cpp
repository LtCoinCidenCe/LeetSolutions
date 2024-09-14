#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  string removeStars(string s)
  {
    int n = s.size();
    string result;
    result.reserve(n);
    for (int i = 0; i < n; i++) {
      char c = s[i];
      if (c != '*')
        result += c;
      else
        result.pop_back();
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "leet**cod*e";
  string &&result = sln.removeStars(s);
  return 0;
}
