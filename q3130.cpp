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
        // think it in a way about concatenation...
        // shorter array can be "stable" with the 1 in the middle.
        // when fetching the previous results dfs(zero - 1, one, 0), it contained that shorter array.
        // but you got this k=0 "HERE ALREADY PLACED NEAR THE SOCKET".
        // and the result taken from the shorter result combined makes a non-stable array.
        // so it gets ruled out.

        // from bottom up inference, there would be no "un-stable" statistic in any dfs(zero,one,k)
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
  int zero = 5;
  int one = 1;
  int limit = 2;
  int result = sln.numberOfStableArrays(zero, one, limit);
  return 0;
}
