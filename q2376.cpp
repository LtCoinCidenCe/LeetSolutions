#include <algorithm>
#include <functional>
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
  int countSpecialNumbers(int n)
  {
    string num = to_string(n);
    int wei = num.size();
    int result = 0;
    int bits[]{9,
               81,
               648,
               4536,
               9 * 9 * 8 * 7 * 6,
               9 * 9 * 8 * 7 * 6 * 5,
               9 * 9 * 8 * 7 * 6 * 5 * 4,
               9 * 9 * 8 * 7 * 6 * 5 * 4 * 3,
               9 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2,
               3265920};
    for (int i = 0; i < wei - 1; i++) {
      result += bits[i];
    }

    function<int(vector<bool>, int, bool)> dfs = [&](vector<bool> used, int i, bool freeNumber) -> int {
      if (i == wei - 1) {
        if (freeNumber) {
          return 10 - i;
        }
        else {
          int count = 0;
          for (int j = i == 0 ? 1 : 0; j <= num[i] - '0'; j++) {
            if (!used[j]) {
              count++;
            }
          }
          return count;
        }
      }
      int sum = 0;
      if (freeNumber) {
        int z = 1;
        int remainingBits = wei - i;
        int remainingDigits = 10 - i;
        for (int j = 0; j < remainingBits; j++) {
          z *= remainingDigits;
          remainingDigits -= 1;
        }
        sum += z;
      }
      else {
        int c = num[i] - '0';
        int repeat = -1;
        for (int j = i == 0 ? 1 : 0; j < c; j++) {
          if (!used[j]) {
            used[j] = true;
            if (repeat == -1) {
              repeat = dfs(used, i + 1, true);
            }
            sum += repeat;
            used[j] = false;
          }
        }
        if (!used[c]) {
          used[c] = true;
          sum += dfs(used, i + 1, false);
          used[c] = false;
        }
      }
      return sum;
    };

    result += dfs(vector<bool>(10, false), 0, false);

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int result = sln.countSpecialNumbers(225);
  return 0;
}
