#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  long long minEnd(int n, int x)
  {
    n = n - 1;
    long long result = x;
    int ox = 0;
    while (n > 0) {
      long long shifted = result >> ox;
      bool occupied = shifted & 1ll;
      if (shifted) {
        if (!occupied) {
          long long number = n & 1;
          number = number << ox;
          result = result | number;
          n = n >> 1;
        }
      }
      else {
        long long number = n;
        number = number << ox;
        result = result | number;
        break;
      }
      ox++;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int n = 3, x = 4;
  long long result = sln.minEnd(n, x);
  return 0;
}
