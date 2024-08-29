#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int minimumSubstringsInPartition(string s)
  {
    int n = s.size();
    if (n < 3) {
      return 1;
    }

    vector<int> freq(26, 0);
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 0;
    int highest = 1, result = 0; // result is how many cuts not how many substrings
    for (int i = 0; i < 2; i++) {
      const char &c = s[i];
      int letterIndex = c - 'a';
      int &lfreq = freq[letterIndex];
      lfreq++;
      highest = max(lfreq, highest);
    }
    for (int i = 2; i < n; i++) {
      const char &c = s[i];
      int letterIndex = c - 'a';
      int &lfreq = freq[letterIndex];
      lfreq++;
      if (lfreq > highest) {
        highest = lfreq;
      }
      if (ranges::all_of(freq, [=](int f) { return f == highest || f == 0; })) {
        result = 0;
        dp[i] = 0;
        continue;
      }
      result = dp[i - 1] + 1;
      dp[i] = result;
      vector<int> rmvfreq = freq;
      for (int j = 0; j < i; j++) {
        const char &rmv = s[j];
        int letterRMV = rmv - 'a';
        rmvfreq[letterRMV]--;
        // int &lrfreq = rmvfreq[letterRMV];
        // lrfreq--;
        int letterRemaining = s[j + 1] - 'a';
        int remainingfreq = rmvfreq[letterRemaining];
        if (ranges::all_of(rmvfreq, [=](int f) { return f == remainingfreq || f == 0; })) {
          result = min(result, dp[j] + 1);
          dp[i] = result;
        }
      }
    }

    return result + 1;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string s = "fabccddg";
  int result = sln.minimumSubstringsInPartition(s);
  return result;
}
