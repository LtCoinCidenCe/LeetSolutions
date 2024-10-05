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
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    int n = days.size();
    vector<int> money(n + 2, 0);
    money[1] = *ranges::min_element(costs);
    int last7 = 0, last30 = 0;
    for (int i = 1; i < n; i++) {
      int date = days.at(i);
      // days[last7] + 7; // bought ticket7, unavailable day
      // days[last30] + 30;
      while (date >= days[last7] + 7) {
        last7++;
      }
      while (date >= days[last30] + 30) {
        last30++;
      }
      // from last7 to i needs 1 ticket 7
      int thisDay = money[i] + costs[0];
      thisDay = min(thisDay, money[last7] + costs[1]);
      thisDay = min(thisDay, money[last30] + costs[2]);
      money[i + 1] = thisDay;
    }
    return money[n];
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> days{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  vector<int> costs{2, 7, 15};
  auto result = sln.mincostTickets(days, costs);
  return 0;
}