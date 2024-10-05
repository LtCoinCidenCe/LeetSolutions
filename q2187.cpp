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

class SolutionSlow {
public:
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    int n = time.size();
    ranges::sort(time);
    vector<long long> schedule;
    long long result = (long long)(time[0]) * (long long)(totalTrips);
    long long temp = time[0];
    for (long long i = 0; i < totalTrips; i++) {
      schedule.emplace_back(temp);
      temp += time[0];
    }

    for (int i = 1; i < n; i++) {

      long long cost = time[i];
      for (long long j = 0; j < totalTrips; j++) {
        auto &finishTime = schedule[totalTrips - 1];
        long long currentTime = cost * (j + 1);
        if (currentTime < finishTime) {
          schedule.pop_back();
          auto insertionPlace = ranges::lower_bound(schedule, currentTime);
          schedule.emplace(insertionPlace, currentTime);
        }
      }
    }
    auto finishOne = schedule[totalTrips - 1];
    return finishOne;
  }
};

class SolutionSlow2 {
public:
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    int n = time.size();
    ranges::sort(time);
    priority_queue<long long> busEnd;

    long long temp = time[0];
    for (long long i = 0; i < totalTrips; i++) {
      busEnd.push(temp);
      temp += time[0];
    }

    for (int index = 1; index < n; index++) {
      temp = time[index];
      for (int i = 0; i < totalTrips; i++) {
        if (temp >= busEnd.top()) {
          break;
        }
        busEnd.pop();
        busEnd.push(temp);
        temp += time[index];
      }
    }

    return busEnd.top();
  }
};

class Solution {
public:
  vector<int> *unitTime;
  long long totalProducts;
  long long productsInTime(long long time)
  {
    long long init = 0;
    for (size_t i = 0; i < unitTime->size(); i++) {
      init += time / unitTime->at(i);
    }
    return init;
  }
  long long minimumTime(vector<int> &time, int totalTrips)
  {
    unitTime = &time;
    totalProducts = totalTrips;
    int minT = *ranges::min_element(time);
    long long left = 1, right = totalProducts * minT;
    while (left < right) {
      long long mid = (left + right) / 2;
      long long yield = productsInTime(mid);
      if (yield < totalProducts) {
        left = mid + 1;
      }
      else {
        // yield >= totalProducts     -----    mid
        right = mid;
      }
    }
    return right;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> time{5, 10, 10};
  int totalTrips = 9;
  long long result = sln.minimumTime(time, totalTrips);
  return 0;
}
