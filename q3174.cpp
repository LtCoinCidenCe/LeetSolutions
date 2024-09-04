#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string clearDigits(string s)
  {
    int n = s.size();
    char *seq = new char[n + 1];
    seq[n] = '\0';
    int index = n;
    int number = 0;
    for (int i = n - 1; i >= 0; i--) {
      char cc = s[i];
      if (cc >= '0' && cc <= '9') {
        number++;
        continue;
      }
      if (number == 0) {
        index--;
        seq[index] = cc;
      }
      else
        number--;
    }
    string result(seq + index);
    delete[] seq;
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "ddfj342ksi34is";
  string result = sln.clearDigits(s);
  return 0;
}