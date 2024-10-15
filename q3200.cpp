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

class Solution {
public:
  int maxHeightOfTriangle(int red, int blue)
  {
    // blue odd
    int blueLevel1 = sqrt(blue);
    int redLevel1 = (-1 + sqrt(1 + red * 4)) / 2;
    // red odd
    int blueLevel2 = (-1 + sqrt(1 + blue * 4)) / 2;
    int redLevel2 = sqrt(red);

    // blue first
    int minimalLevel = min(blueLevel1, redLevel1);
    int result;
    if (minimalLevel <= 0)
      result = 1;
    else {
      if (blueLevel1 >= redLevel1 + 1)
        result = redLevel1 * 2 + 1;
      else {
        result = blueLevel1 * 2;
      }
    }

    // red first
    minimalLevel = min(blueLevel2, redLevel2);
    int result2 = 1;
    if (minimalLevel <= 0)
      return result;
    else {
      if (redLevel2 >= blueLevel2 + 1)
        result2 = blueLevel2 * 2 + 1;
      else {
        result2 = redLevel2 * 2;
      }
    }
    return max(result, result2);
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  auto result = sln.maxHeightOfTriangle(1, 2);
  return 0;
}
