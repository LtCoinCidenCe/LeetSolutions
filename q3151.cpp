#include <vector>
using namespace std;

class Solution {
public:
  bool isArraySpecial(vector<int> &nums)
  {
    int n = nums.size();
    bool odd = nums[0] & 1;
    for (int i = 1; i < n; i++) {
      if (bool(nums[i] & 1) == odd)
        return false;
      odd = !odd;
    }
    return true;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}