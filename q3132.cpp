#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumAddedInteger(vector<int> &nums1, vector<int> &nums2)
  {
    int n = nums1.size(), m = nums2.size();
    ranges::sort(nums1);
    ranges::sort(nums2);
    for (int i = 3 - 1; i >= 0; i--) {
      int diff = nums2[0] - nums1[i];
      int one = i + 1, two = 1;
      while (one < n && two < m) {
        if (nums2[two] - nums1[one] == diff) {
          two++;
        }
        one++;
      }
      if (two == m) {
        return diff;
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums1{4, 20, 16, 12, 8};
  vector<int> nums2{14, 18, 10};
  int result = sln.minimumAddedInteger(nums1, nums2);
  return 0;
}
