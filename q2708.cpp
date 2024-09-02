#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  long long maxStrength(vector<int> &nums)
  {
    int n = nums.size();
    long long result = nums[0];

    bool zeroFlag = false;
    bool justify = false;
    int minusIndex = -1;
    int firstIndex = 0;
    for (firstIndex = 0; firstIndex < n; firstIndex++) {
      result = nums[firstIndex];
      if (result != 0) {
        break;
      }
      else
        zeroFlag = true;
    }
    int minusCount = 0;
    if (result < 0) {
      minusIndex = firstIndex;
      minusCount++;
    }
    else if (result > 0)
      justify = true;

    for (int i = firstIndex + 1; i < n; i++) {
      int number = nums[i];
      if (number > 0)
        justify = true;
      if (number != 0)
        result *= number;
      else
        zeroFlag = true;
      if (number < 0) {
        minusCount++;
        if (minusIndex == -1) {
          minusIndex = i;
          continue;
        }
        if (nums[minusIndex] < number) {
          minusIndex = i;
        }
      }
    }

    if (result < 0) {
      if (minusCount > 2 | justify) {
        result /= nums[minusIndex];
      }
      else if (zeroFlag) {
        result = 0;
      }
    }

    return result;
  }
};

class SolutionOld {
public:
  long long maxStrength(vector<int> &nums)
  {
    int n = nums.size();
    ranges::sort(nums);

    vector<int>::iterator zeroBound = ranges::lower_bound(nums, 0);
    vector<int>::iterator oneBound = ranges::upper_bound(nums, 1);
    int zeroIndex = zeroBound - nums.begin(); // could be end()
    int oneIndex = oneBound - nums.begin();

    bool minusAvailable = zeroIndex > 1;
    bool posAvailable = oneIndex < n;
    long long result = nums[n - 1];

    if (posAvailable) {
      for (int i = n - 2; i >= oneIndex; i--) {
        result *= nums[i];
      }
    }

    long long mmm = 1;
    if (minusAvailable) {
      for (int i = 0; i < zeroIndex; i++) {
        mmm *= nums[i];
      }
      if ((zeroIndex & 1) == 1) {
        mmm /= nums[zeroIndex - 1];
      }
    }

    if (posAvailable && minusAvailable) {
      return mmm * result;
    }
    else if (minusAvailable) {
      return mmm;
    }
    else {
      return result;
    }
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{2, 2, 7, 0, -4, 9, 4};
  long long result = sln.maxStrength(nums);
  return 0;
}
