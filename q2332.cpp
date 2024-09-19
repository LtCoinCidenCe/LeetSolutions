#include <algorithm>
#include <climits>
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
  int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
  {
    int n = buses.size();
    int m = passengers.size();
    // records last passenger
    vector<int> busLastPassenger(n, -1);
    vector<bool> busFull(n, true);
    ranges::sort(buses);
    ranges::sort(passengers);

    int passengerPtr = 0;
    for (int i = 0; i < n; i++) {
      if (passengerPtr >= m)
        return buses[n - 1]; // more buses than people
      int busTime = buses[i];
      bool goPassenger = passengers[passengerPtr] <= busTime;
      if (!goPassenger) {
        busLastPassenger[i] = passengerPtr - 1;
        busFull[i] = false;
        continue;
      }
      int passengerLimit = upper_bound(passengers.begin() + passengerPtr, passengers.end(), busTime) -
                           (passengers.begin() + passengerPtr);

      if (passengerLimit >= capacity) {
        // the bus is full
        passengerPtr += capacity;
        busLastPassenger[i] = passengerPtr - 1;
      }
      else {
        passengerPtr += passengerLimit;
        busLastPassenger[i] = passengerPtr - 1;
        busFull[i] = false;
      }
    }
    // bus capacity 'somehow' full occupied
    // take not-full bus
    // take gap
    int lastP = busLastPassenger[n - 1];
    int targetTime;
    if (busFull[n - 1]) {
      targetTime = passengers[lastP];
      for (int i = lastP; i >= 0; i--) {
        if (targetTime != passengers[i]) {
          return targetTime;
        }
        targetTime--;
      }
      return targetTime;
    }

    // bus not full
    targetTime = buses[n - 1];
    for (int i = lastP; i >= 0; i--) {
      if (targetTime != passengers[i]) {
        return targetTime;
      }
      targetTime--;
    }
    return targetTime;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> bus{3};
  vector<int> passengers{4};
  int capacity = 1;
  sln.latestTimeCatchTheBus(bus, passengers, capacity);
  return 0;
}
