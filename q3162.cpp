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
  int numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
  {
    int n = nums1.size(), m = nums2.size();
    int result = 0;
    for (int i = 0; i < n; i++) {
      int i1 = nums1[i];
      if (i1 % k == 0) {
        int i2 = i1 / k;
        for (int j = 0; j < m; j++) {
          if (i2 % nums2[j] == 0) {
            result++;
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
