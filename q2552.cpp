#include <algorithm>
#include <memory>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  long long countQuadruplets(vector<int> &nums)
  {
    const int n = nums.size();
    long long result = 0;
    vector<int> smallerThanIndexCount(n + 1, 0); // for nums lefter than j
    for (int j = 0; j < n - 1; j++) {
      int right = 0; // ok j fixed;
      const int &numj = nums[j];
      for (int k = n - 1; k > j; k--) {
        const int &numk = nums[k];
        if (numj > numk) {
          // add numbers;
          // 1 3 2 4  numk==2 therefore
          result += smallerThanIndexCount[numk] * right;
        }
        else {
          // numj < numk by constrain
          // remember j fixed
          // therefore greater than j count ++
          right++;
        }
      }
      for (int lf = numj + 1; lf <= n; lf++) {
        // maintain the counts
        // could be Binary Indexed Tree?
        smallerThanIndexCount[lf]++;
      }
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{1, 3, 2, 4, 5};
  long long result = sln.countQuadruplets(nums);
  return 0;
}
