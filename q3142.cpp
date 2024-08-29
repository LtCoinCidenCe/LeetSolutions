#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  bool satisfiesConditions(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    for (int j = 0; j < m - 1; j++) {
      if (grid[0][j] == grid[0][j + 1]) {
        return false;
      }
    }
    for (int j = 0; j < m; j++) {
      if (!ranges::all_of(grid, [&](const vector<int> &a) { return a[j] == grid[0][j]; })) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char **argv) { return 0; }
