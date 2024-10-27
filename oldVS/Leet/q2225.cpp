#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        map<int, int>playerLoss;
        for (int i = 0; i < n; i++)
        {
            const vector<int>& m = matches[i];
            if (playerLoss.find(m[0]) == playerLoss.end())
            {
                playerLoss[m[0]] = 0;
            }
            if (playerLoss.find(m[1]) == playerLoss.end())
            {
                playerLoss[m[1]] = 1;
            }
            else
                playerLoss[m[1]]++;
        }
        vector<vector<int>>result(2);
        for (map<int, int>::iterator i = playerLoss.begin(); i != playerLoss.end(); i++)
        {
            int losses = i->second;
            if (losses == 0)
            {
                result[0].push_back(i->first);
            }
            else if (losses == 1)
            {
                result[1].push_back(i->first);
            }
        }
        return result;
    }
};

int q2225()
{
    Solution s;
    vector<vector<int>>vv{ {1,3} ,{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9} };
    auto result = s.findWinners(vv);
    return 0;
}
