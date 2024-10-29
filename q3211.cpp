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
  vector<string> validStrings(int n)
  {
    string play = "";
    vector<string> result;
    function<void()> dfs = [&]() {
      if (play.size() == n) {
        result.push_back(play);
        return;
      }
      if (!play.ends_with('0')) {
        play += '0';
        dfs();
        play.back() = '1';
      }
      else {
        play += '1';
      }
      dfs();
      play.pop_back();
    };
    dfs();
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  auto result = sln.validStrings(6);
  return 0;
}
