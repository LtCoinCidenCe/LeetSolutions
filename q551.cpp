#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  bool checkRecord(string s)
  {
    int n = s.size();
    int a = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
      const char &c = s[i];
      switch (c) {
      case 'A':
        a++;
        l = 0;
        break;
      case 'L':
        l++;
        break;
      default:
        l = 0;
        break;
      }
      if (a >= 2) {
        return false;
      }
      if (l >= 3) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "PPALLP";
  bool result = sln.checkRecord(s);
  return 0;
}
