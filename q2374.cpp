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
  int edgeScore(vector<int> &edges)
  {
    int n = edges.size();
    vector<long long> points(n, 0);
    for (int i = 0; i < n; i++) {
      int e = edges.at(i);
      points[e] += i;
    }
    int resultIndex = 0;
    for (int i = 0; i < n; i++) {
      if (points[i] > points[resultIndex])
        resultIndex = i;
    }

    return resultIndex;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
