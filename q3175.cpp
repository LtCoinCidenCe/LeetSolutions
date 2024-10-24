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
  int findWinningPlayer(vector<int> &skills, int k)
  {
    if (k == 1)
      return skills[0] > skills[1] ? 0 : 1;
    size_t n = skills.size();
    int top = skills[0];
    int streak = 0, index = 0;
    for (size_t i = 1; i < n; i++) {
      if (skills[i] > top) {
        top = skills[i];
        index = i;
        streak = 1;
      }
      else {
        streak++;
        if (streak == k)
          return index;
      }
    }
    return index;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
