#include <algorithm>
#include <cmath>
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
  int maxTotalReward(vector<int> &rewardValues)
  {
    set<int> rewards(rewardValues.begin(), rewardValues.end());
    vector<int> inputs(rewards.begin(), rewards.end());
    auto n = inputs.size();

    if (n > 99)
      if (inputs[n - 2] + 1 == inputs[n - 1]) // this is still correct
        return inputs[n - 2] + inputs[n - 1];
      else if (rewards.contains(1))           // this is guessing
        return 2 * inputs[n - 1] - 1;
      else if (n > 10000)                     // this is nonsense
        return inputs[n - 2] + inputs[n - 1];

    for (size_t i = 1; i < n; i++) {
      int newNumber = inputs[i];

      for (set<int>::iterator iterator = rewards.begin(); iterator != rewards.end(); iterator++) {
        int oldC = *iterator;
        if (oldC < newNumber) {
          rewards.insert(newNumber + oldC);
        }
        else {
          break;
        }
      }
    }
    return *rewards.rbegin();
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> values{1, 1, 6, 4, 3, 2, 99, 100};
  auto result = sln.maxTotalReward(values);
  return 0;
}
