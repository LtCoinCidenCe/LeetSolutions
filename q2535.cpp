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
  int differenceOfSum(vector<int> &nums)
  {
    int elemental = 0, digital = 0;
    for (int i = 0; i < nums.size(); i++) {
      int w = nums.at(i);
      elemental += w;
      string st = to_string(w);
      for (size_t i = 0; i < st.size(); i++) {
        char c = st[i];
        int a = c - '0';
        digital += a;
      }
    }
    return elemental - digital;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
