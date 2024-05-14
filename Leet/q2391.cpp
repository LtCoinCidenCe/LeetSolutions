#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int time = 0;
        int lastm = 0, lastp = 0, lastg = 0;
        time += garbage[0].size();
        for (int i = 1; i < n; i++)
        {
            const string& gg = garbage[i];
            for (int j = 0; j < gg.size(); j++)
            {
                if (gg[j] == 'M')
                {
                    time += 1;
                    for (int o = lastm; o < i; o++)
                    {
                        time += travel[o];
                    }
                    lastm = i;
                }
                if (gg[j] == 'P')
                {
                    time += 1;
                    for (int o = lastp; o < i; o++)
                    {
                        time += travel[o];
                    }
                    lastp = i;
                }
                if (gg[j] == 'G')
                {
                    time += 1;
                    for (int o = lastg; o < i; o++)
                    {
                        time += travel[o];
                    }
                    lastg = i;
                }
            }
        }
        return time;
    }
};

int q2391()
{
    Solution s;
    vector<string>garbage{ "MMM","PGM","GP" };
    vector<int>travel{ 3,10 };
    int result = s.garbageCollection(garbage, travel);
    return result;
}