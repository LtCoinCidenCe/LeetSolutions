#include <vector>
using namespace std;

class Solution {
public:
  bool canMakeSquare(vector<vector<char>> &grid)
  {
    const int ADVANTAGE = 2;
    vector<int> square(4, grid[1][1] == 'B' ? 1 : -1);

    grid[0][0] == 'B' ? square[0]++ : square[0]--;
    if (grid[0][1] == 'B') {
      square[0]++;
      square[1]++;
    }
    else {
      square[0]--;
      square[1]--;
    }
    if (grid[1][0] == 'B') {
      square[0]++;
      square[2]++;
    }
    else {
      square[0]--;
      square[2]--;
    }

    if (abs(square[0]) >= ADVANTAGE)
      return true;

    grid[0][2] == 'B' ? square[1]++ : square[1]--;
    if (grid[1][2] == 'B') {
      square[1]++;
      square[3]++;
    }
    else {
      square[1]--;
      square[3]--;
    }

    if (abs(square[1]) >= ADVANTAGE)
      return true;

    grid[2][0] == 'B' ? square[2]++ : square[2]--;
    if (grid[2][1] == 'B') {
      square[2]++;
      square[3]++;
    }
    else {
      square[2]--;
      square[3]--;
    }

    if (abs(square[2]) >= ADVANTAGE)
      return true;

    grid[2][2] == 'B' ? square[3]++ : square[3]--;
    if (abs(square[3]) >= ADVANTAGE)
      return true;

    return false;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<vector<char>> grid{{'W', 'B', 'B'}, {'B', 'W', 'W'}, {'B', 'W', 'B'}};
  sln.canMakeSquare(grid);
  return 0;
}