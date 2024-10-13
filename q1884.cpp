#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <ranges>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution2 {
public:
  int twoEggDrop(int n)
  {
    double result = (-1 + sqrt(1 + 8 * n)) / 2;
    return ceil(result);
  }
};

class Solution {
public:
  int twoEggDrop(int n)
  {
    if (n == 1)
      return 1;
    if (n < 4)
      return 2;
    for (int f = 3; f < 100; f++) {
      int limit = ((f + 1) * (f)) / 2;
      if (n <= limit) {
        return f;
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  Solution2 sln;
  auto result = sln.twoEggDrop(100);

  return 0;
}
