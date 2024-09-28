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
  int timeRequiredToBuy(vector<int> &tickets, int k)
  {
    int n = tickets.size();
    int tallest = tickets[k];
    int secondTallest = tallest - 1;
    int result = 0;
    int i = 0;
    for (; i <= k; i++) {
      int tick = tickets[i];
      result += tick > tallest ? tallest : tick;
    }
    for (; i < n; i++) {
      int tick = tickets[i];
      result += tick > secondTallest ? secondTallest : tick;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> tickets{2, 3, 2};
  int k = 2;
  auto result = sln.timeRequiredToBuy(tickets, k);
  return 0;
}
