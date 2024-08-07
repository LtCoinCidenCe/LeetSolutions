#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  int addedInteger(vector<int> &nums1, vector<int> &nums2)
  {
    auto min1 = ranges::min_element(nums1);
    auto min2 = ranges::min_element(nums2);
    return *min2 - *min1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums1{2, 6, 4};
  vector<int> nums2{9, 7, 5};
  int result = sln.addedInteger(nums1, nums2);
  return 0;
}
