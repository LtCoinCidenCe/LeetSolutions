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
  double nthPersonGetsNthSeat(int n)
  {
    double result = 0.5;
    if (n == 1) {
      result = 1;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int n = 5;
  double result = sln.nthPersonGetsNthSeat(n);
  return 0;
}
