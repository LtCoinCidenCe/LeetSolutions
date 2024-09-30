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

class SeatManager {
public:
  priority_queue<int, vector<int>, greater<int>> pq;
  int seats;
  int current = 1;
  SeatManager(int n)
  {
    // just this easy!
    seats = n;
  }

  int reserve()
  {
    if (!pq.empty()) {
      int result = pq.top();
      pq.pop();
      return result;
    }
    return current++;
  }

  void unreserve(int seatNumber)
  {
    // just push?
    pq.push(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main(int argc, char **argv) { return 0; }
