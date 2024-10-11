#include <algorithm>
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
  int duplicateNumbersXOR(vector<int> &nums)
  {
    int result = 0, n = nums.size();
    unordered_set<int> theSet;
    for (int i = 0; i < n; i++) {
      int a = nums.at(i);
      if (theSet.contains(a)) {
        result = (result ^ a);
      }
      theSet.insert(a);
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
