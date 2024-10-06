#include <algorithm>
#include <functional>
#include <iostream>
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
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int n = gas.size();
    int tank = 0;
    int refuelMin = 0, refuelIndex = n - 1;
    for (int i = 0; i < n; i++) {
      int g = gas[i];
      int c = cost[i];
      tank -= c; // consumption point
      tank += g; // refueling point
      if (tank < refuelMin) {
        refuelIndex = i;
        refuelMin = tank;
      }
    }
    if (tank < 0) {
      return -1;
    }
    return (refuelIndex + 1) % n;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> gas{1, 2, 3, 4, 5};
  vector<int> cost{3, 4, 5, 1, 2};
  auto result = sln.canCompleteCircuit(gas, cost);
  return 0;
}
