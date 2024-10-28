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
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    vector<int> parents(n + 1, 0);
    int doubleParent = 0;
    vector<int> secondEdge;

    vector<int> theStack;
    unordered_set<int> quickReference;
    function<bool(int)> dfs = [&](int vertex) {
      while (vertex) {
        if (quickReference.contains(vertex)) {
          theStack.push_back(vertex);
          return true;
        }
        theStack.push_back(vertex);
        quickReference.insert(vertex);
        vertex = parents[vertex];
      }
      return false;
    };

    for (auto &&i : edges) {
      if (parents[i[1]] == 0)
        parents[i[1]] = i[0];
      else {
        doubleParent = i[1];
        secondEdge = i;
      }
    }
    if (doubleParent != 0) {
      if (dfs(doubleParent)) {
        return vector<int>{parents[doubleParent], doubleParent};
      }
      return secondEdge;
    }

    bool found = dfs(1);
    auto loopPoint = theStack.back();
    auto point = ranges::find(theStack, loopPoint);
    quickReference.clear();
    quickReference.insert(point, theStack.end());
    for (int i = n - 1; i >= 0; i--) {
      auto &check = edges[i];
      if (quickReference.contains(check[0]) && quickReference.contains(check[1]))
        return check;
    }

    return vector<int>(); // useless
  };
};

int main(int argc, char **argv)
{
  Solution sln;
  vector<vector<int>> edges{{2, 1}, {3, 1}, {4, 2}, {1, 4}};
  auto result = sln.findRedundantDirectedConnection(edges);
  return 0;
}
