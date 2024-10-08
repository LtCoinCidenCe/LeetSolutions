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
  string destCity(vector<vector<string>> &paths)
  {
    int routes = paths.size();
    unordered_set<string> departures;
    vector<bool> solved;
    for (int i = 0; i < routes; i++) {
      const auto &depart = paths[i][0];
      departures.insert(depart);
    }
    for (int i = 0; i < routes; i++) {
      const auto &desti = paths[i][1];
      if (!departures.contains(desti))
        return desti;
    }
    return "";
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
