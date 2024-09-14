#include <set>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfPoints(vector<vector<int>> &nums)
  {
    int n = nums.size();
    set<int> points;
    for (int i = 0; i < n; i++) {
      const vector<int> &car = nums[i];
      for (int j = car[0]; j <= car[1]; j++) {
        points.insert(j);
      }
    }
    return points.size();
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}