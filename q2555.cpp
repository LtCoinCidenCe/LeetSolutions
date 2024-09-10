#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool doesntOverlap(const pair<int, int> &p1, const pair<int, int> &p2)
  {
    if (p1.first > p2.first)
      return doesntOverlap(p2, p1);
    if (p1.second < p2.first)
      return true;
    else
      return false;
  }
  int maximizeWin(vector<int> &prizePositions, int k)
  {
    int n = prizePositions.size();

    // adjacent
    queue<pair<int, int>> prizes;
    prizes.emplace(prizePositions[0], 1);
    int score = 1;

    queue<pair<int, int>> secondPrize;
    secondPrize.emplace(prizePositions[0], 1);
    int secondScore = 1;
    int result = score;

    vector<pair<int, pair<int, int>>> pq;
    for (int i = 1; i < n; i++) {
      int position = prizePositions[i];
      if (prizes.back().first == position) {
        prizes.back().second++;
        score++;
      }
      else {
        prizes.emplace(position, 1);
        if (position <= prizes.front().first + k + k + 1) {
          score++;
        }
        else {
          while (position > prizes.front().first + k + k + 1) {
            score -= prizes.front().second;
            prizes.pop();
          }
          score += 1;
        }
      }
      result = max(result, score);

      if (secondPrize.back().first == position) {
        secondPrize.back().second++;
        secondScore++;
      }
      else {
        if (position <= secondPrize.front().first + k) {
          secondScore++;
          secondPrize.emplace(position, 1);
        }
        else {
          pq.push_back(pair(secondScore, pair(secondPrize.front().first, secondPrize.back().first)));
          secondPrize.emplace(position, 1);
          while (position > secondPrize.front().first + k) {
            secondScore -= secondPrize.front().second;
            secondPrize.pop();
          }

          secondScore += 1;
        }
      }
    }
    pq.push_back(pair(secondScore, pair(secondPrize.front().first, secondPrize.back().first)));

    for (int i = 0; i < pq.size(); i++) {
      for (int j = i + 1; j < pq.size(); j++) {
        auto &top1 = pq[i];
        auto &top2 = pq[j];
        if (doesntOverlap(top1.second, top2.second)) {
          result = max(result, top1.first + top2.first);
        }
      }
    }

    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<int> nums{1, 1, 2, 2, 4, 4, 4, 6, 6, 6, 9, 9};
  int result = sln.maximizeWin(nums, 2);
  return 0;
}
