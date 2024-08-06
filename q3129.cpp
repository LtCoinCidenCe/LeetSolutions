#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
  int MOD = 1'000'000'007;
  vector<vector<vector<int>>> memory;
  int limit = 0;
  long long dfs(int zero, int one, int k)
  {
    if (zero == 0) {
      return k == 1 && one <= limit;
    }
    if (one == 0) {
      return k == 0 && zero <= limit;
    }
    int &res = memory[zero][one][k];
    if (res != -1) {
      return res;
    }
    if (k == 0) {
      int deduct = 0;
      if (zero > limit) {
        deduct = dfs(zero - limit - 1, one, 1);
      }
      res = ((long long)(dfs(zero - 1, one, 0)) + dfs(zero - 1, one, 1) + (MOD - deduct)) % MOD;
    }
    else {
      int deduct = 0;
      if (one > limit) {
        deduct = dfs(zero, one - limit - 1, 0);
      }
      res = ((long long)(dfs(zero, one - 1, 0)) + dfs(zero, one - 1, 1) + (MOD - deduct)) % MOD;
    }

    return res;
  }

  int numberOfStableArrays(int zero, int one, int limit)
  {
    this->limit = limit;
    memory.resize(zero + 1);
    ranges::for_each(memory, [&](vector<vector<int>> &ones) {
      ones.resize(one + 1);
      ranges::for_each(ones, [&](vector<int> &must) {
        must.resize(2, -1);
        9;
      });
    });

    return (dfs(zero, one, 0) + dfs(zero, one, 1)) % MOD;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int zero = 3;
  int one = 3;
  int limit = 2;
  int result = sln.numberOfStableArrays(zero, one, limit);
  return 0;
}
