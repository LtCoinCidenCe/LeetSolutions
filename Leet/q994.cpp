#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;

        int total = 0;
        int rotten = 0;
        int currentLevel = 0;
        int nextLevel = 0;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (grid[j][i] == 1)
                {
                    total++;
                }
                if (grid[j][i] == 2)
                {
                    q.emplace(j, i);
                    total++;
                    rotten++;
                    currentLevel++;
                }
            }
        }

        int minute = 0;
        while (!q.empty())
        {
            if (currentLevel == 0)
            {
                minute++;
                currentLevel = nextLevel;
                nextLevel = 0;
            }
            pair<int, int>badorange = q.front();
            q.pop();
            currentLevel--;
            int x, y;
            y = badorange.first;
            x = badorange.second;
            if (x - 1 >= 0)
            {
                //(y,x-1)
                if (grid[y][x - 1] == 1)
                {
                    rotten++;
                    grid[y][x - 1] = 2;
                    q.emplace(y, x - 1);
                    nextLevel++;
                }
            }
            if (x + 1 < n)
            {
                if (grid[y][x + 1] == 1)
                {
                    rotten++;
                    grid[y][x + 1] = 2;
                    q.emplace(y, x + 1);
                    nextLevel++;
                }
            }
            if (y - 1 >= 0)
            {
                if (grid[y - 1][x] == 1)
                {
                    rotten++;
                    grid[y - 1][x] = 2;
                    q.emplace(y - 1, x);
                    nextLevel++;
                }
            }
            if (y + 1 < m)
            {
                if (grid[y + 1][x] == 1)
                {
                    rotten++;
                    grid[y + 1][x] = 2;
                    q.emplace(y + 1, x);
                    nextLevel++;
                }
            }
        }
        if (rotten == total)
        {
            return minute;
        }
        else
        {
            return -1;
        }
    }
};

int q994()
{
    Solution s;
    vector<vector<int>>oranges{
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int result = s.orangesRotting(oranges);
    return 0;
}