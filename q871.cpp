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

class SolutionProcessDP {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
  {
    int n = stations.size();
    if (n == 0) {
      return startFuel - target >= 0 ? 0 : -1;
    }

    vector<vector<long long>> fuel; // [station][howManyStationsSkipped]=remainingFuel
    fuel.resize(n);

    int car = 0;
    long long remainFuel = startFuel;
    // first station
    const auto &s = stations[0];
    int costDistance = s[0] - car;
    remainFuel = remainFuel - costDistance; // consume fuel
    if (remainFuel < 0)                     // could not reach
      return -1;
    int thisSkipped = remainFuel;
    remainFuel += s[1]; // refuel
    car = s.at(0);

    fuel[0].resize(2);
    fuel[0][0] = remainFuel;
    fuel[0][1] = thisSkipped;
    // end of first station
    for (int i = 1; i < n; i++) {
      const auto &s = stations[i];
      int costDistance = s[0] - car;

      // drivable
      remainFuel = remainFuel - costDistance; // consume fuel
      if (remainFuel < 0)                     // could not reach
        return -1;
      long long thisSkipped = remainFuel;
      remainFuel += s[1]; // refuel
      car = s.at(0);

      fuel[i].resize(i + 2, -1);
      fuel[i][0] = (remainFuel);
      fuel[i][1] = (thisSkipped); // temp value, reachable but not most fuel

      for (int j = 1; j <= i; j++) {
        // i + 1 stations count till now == skip chances
        // j skip times
        // so with j skip times, j-1 is the lowest possible station
        // but it doesn't matter where skipped because fuel[i][j] is always best fuel
        long long drivable = -1;
        long long highestFuel = INT32_MIN;
        // 1. skip this station from [j-1]
        drivable = fuel[i - 1][j - 1] - costDistance;
        highestFuel = drivable;
        // 2. do not skip this station from [j]
        drivable = -1;
        drivable = fuel[i - 1][j] - costDistance;
        if (drivable >= 0)
          highestFuel = max(highestFuel, drivable + s.at(1));
        fuel[i][j] = highestFuel;
      }
      fuel[i][i + 1] = fuel[i - 1][i] - costDistance;
    }
    int finalDistance = target - car;
    for (int i = n; i >= 0; i--) {
      if (fuel[n - 1][i] >= finalDistance) {
        return n - i;
      }
    }
    return -1;
  }
};

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
  {
    priority_queue<int> fuels;
    stations.push_back({target, 0});
    int refuel = 0;
    int car = 0;
    for (size_t i = 0; i < stations.size(); i++) {
      const auto &s = stations[i];
      startFuel -= s[0] - car;
      while (startFuel < 0) {
        if (fuels.empty())
          return -1;
        auto takeout = fuels.top();
        refuel++;
        startFuel += takeout;
        fuels.pop();
      }
      car = s[0];
      fuels.push(s[1]);
    }
    if (startFuel >= 0)
      return refuel;
    else
      return -1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int target = 100;
  int startFuel = 10;
  vector<vector<int>> stations{
      {10, 60},
      {20, 30},
      {30, 30},
      {60, 40},
  };
  vector<vector<int>> stations2{
      {25, 30},
  };

  auto result = sln.minRefuelStops(target, startFuel, stations2);
  return 0;
}
