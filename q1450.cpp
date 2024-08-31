#include <vector>
using namespace std;

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
  {
    int result = 0, n = startTime.size();
    for (int i = 0; i < n; i++) {
      const int &start = startTime[i];
      const int &end = endTime[i];
      if (start <= queryTime && queryTime <= end)
        result++;
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}