#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int maxScore(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    int result = INT_MIN;
    // vector<vector<int>> points(m, vector<int>(n, 0));
    vector<int> columnBest(n, INT_MIN);

    // first row
    int rowBest = -grid[0][0];
    columnBest[0] = rowBest;
    // points[0][0] = rowBest;
    for (int j = 1; j < n; j++) {
      int cell = grid[0][j];
      int newPoint = cell + rowBest;
      result = max(result, newPoint);

      rowBest = max(-cell, rowBest);
      columnBest[j] = rowBest;
      // points[0][j] = rowBest;
    }

    // after first row
    for (int i = 1; i < m; i++) {
      rowBest = -grid[i][0];
      int &firstBest = rowBest;
      if (columnBest[0] >= rowBest) {
        firstBest = columnBest[0];
        int newPoint = grid[i][0] + firstBest;
        result = max(result, newPoint);
      }
      columnBest[0] = firstBest;
      // points[i][0] = firstBest;

      for (int j = 1; j < n; j++) {
        int cell = grid[i][j];
        int best = max(columnBest[j], rowBest);
        int newPoint = cell + best;
        result = max(result, newPoint);

        columnBest[j] = max(-cell, best);
        rowBest = max(-cell, best);
        // points[i][j] = max(-cell, rowBest);
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<vector<int>> grid{{9, 5, 7, 3}, {8, 9, 6, 1}, {6, 7, 14, 3}, {2, 5, 3, 1}};
  vector<vector<int>> grid2{{4, 3, 2}, {3, 2, 1}};
  vector<vector<int>> grid3{{4, 8, 7}, {6, 3, 10}};
  int result = sln.maxScore(grid3);
  return 0;
}
