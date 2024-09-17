#include <algorithm>
#include <queue>
#include <ranges>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
  {
    if (source == target) {
      return 0;
    }

    int routeCount = routes.size();
    unordered_map<int, vector<int>> stationsToBusNo;
    for (int i = 0; i < routeCount; i++) {
      for (int j = 0; j < routes[i].size(); j++) {
        int station = routes[i][j];
        stationsToBusNo[station].push_back(i);
      }
    }
    int result = -1;
    int transit = 1;
    vector<bool> visited(routeCount, false);
    auto &busesDefirstStation = stationsToBusNo[source];
    queue<int> buses;
    for (auto i = busesDefirstStation.begin(); i != busesDefirstStation.end(); i++) {
      auto route = *i;
      buses.push(route);
      visited[route] = true;
    }

    int remaining = buses.size();
    while (!buses.empty()) {
      auto route = buses.front();
      buses.pop();

      for (int u = 0; u < routes[route].size(); u++) {
        int station = routes[route][u];
        if (station == target)
          return transit;
        auto &lines = stationsToBusNo[station];

        for (auto &&line : lines) {
          if (!visited[line]) {
            buses.push(line);
            visited[line] = true;
          }
        }
      }

      remaining--;
      if (remaining == 0) {
        transit++;
        remaining = buses.size();
      }
    }
    return -1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<vector<int>> routes{{1, 2, 7}, {3, 6, 7}};
  int result = sln.numBusesToDestination(routes, 1, 6);
  return 0;
}
