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
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    // vector<vector<unsigned char>> theGraph(n + 1, vector<unsigned char>(n + 1, 0));
    vector<vector<int>> slaves(n + 1, vector<int>());
    for (auto &&i : edges) {
      // theGraph[i[0]][i[1]] = 1;
      // theGraph[i[1]][i[0]] = 1;
      slaves[i[0]].push_back(i[1]);
      slaves[i[1]].push_back(i[0]);
    }
    vector<int> theStack;
    unordered_set<int> quickReference;
    function<bool(int, int)> dfs = [&](int vertex, int last) {
      if (quickReference.contains(vertex)) {
        theStack.push_back(vertex);
        return true;
      }
      theStack.push_back(vertex);
      quickReference.insert(vertex);
      for (auto &&i : slaves[vertex]) {
        if (i != last) {
          if (dfs(i, vertex)) {
            return true;
          }
        }
      }
      theStack.pop_back();
      return false;
    };
    dfs(1, 0);
    auto loopPoint = theStack.back();
    auto point = ranges::find(theStack, loopPoint);
    quickReference.clear();
    quickReference.insert(point, theStack.end());
    for (int i = n - 1; i >= 0; i--) {
      auto &check = edges[i];
      if (quickReference.contains(check[0]) && quickReference.contains(check[1]))
        return check;
    }
    return edges[edges.size() - 1]; // useless
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<vector<int>> edges{{1, 2}, {2, 3}, {1, 3}};
  auto result = sln.findRedundantConnection(edges);
  return 0;
}
