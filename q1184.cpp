#include <vector>
using namespace std;

class Solution {
public:
  int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
  {
    int n = distance.size();
    int cw = start, acw = start;
    int dcw = 0, dacw = 0;
    while (cw != destination) {
      dcw += distance[cw];
      cw++;
      if (cw == n) {
        cw = 0;
      }
    }

    while (acw != destination) {
      acw--;
      if (acw == -1) {
        acw = n - 1;
      }
      dacw += distance[acw];
    }

    return min(dcw, dacw);
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  return 0;
}
