#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumOperationsToMakeKPeriodic(string word, int k)
  {
    int n = word.size();
    int groups = n / k;
    int highscore = 0;
    unordered_map<string, int> freq;
    for (int i = 0; i < n; i += k) {
      int &candidate = freq[word.substr(i, k)];
      candidate++;
      highscore = max(highscore, candidate);
    }
    int result = groups - highscore;
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string word = "leetcodeleet";
  int k = 4;
  int result = sln.minimumOperationsToMakeKPeriodic(word, k);
  return 0;
}
