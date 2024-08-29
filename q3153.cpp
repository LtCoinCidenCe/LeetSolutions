#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  long long sumDigitDifferences(vector<int> &nums)
  {
    int n = nums.size();
    string a = to_string(nums[0]);
    int l = a.size();
    typedef vector<int> digit;
    vector<digit> dp(l, digit(10, 0));
    long long result = 0;
    for (size_t i = 0; i < l; i++) {
      digit &wei = dp[i];
      wei[int(a[i] - '0')]++;
    }

    for (int j = 1; j < n; j++) {
      string a = to_string(nums[j]);
      for (int i = 0; i < l; i++) {
        digit &wei = dp[i];
        long long plus = j;
        int &history = wei[int(a[i] - '0')];
        plus -= history;
        history++;
        result += plus;
      }
    }

    return result;
  }
};

int main()
{
  Solution sln;
  vector<int> nums{13, 23, 12};
  vector<int> nums2{10, 10, 10, 10};
  long long result = sln.sumDigitDifferences(nums2);
  return 0;
}
