#include<vector>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        // quality == time
        int n = quality.size();
        vector<int> h(n, 0);
        iota(h.begin(), h.end(), 0);
        sort(h.begin(), h.end(), [&](int& a, int& b) {
            // time[a]/wage[a]>time[b]/wage[b]
            return quality[a] * wage[b] > quality[b] * wage[a];
            });

        double result = 1e10;
        double rate = 1e9;
        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>q;
        for (int i = 0; i < k; i++) // h[i]
        {
            time += quality[h[i]];
            q.emplace(quality[h[i]], h[i]); // most time comes first
        }
        rate = double(wage[h[k - 1]]) / quality[h[k - 1]];
        double money = time * rate;
        for (int i = k; i < n; i++) // h[i] a person with lower rate
        {
            auto highestTime = q.top();
            int thisTime = quality[h[i]];
            if (thisTime < highestTime.first)
            {
                double thisRate = double(wage[h[i]]) / thisTime;
                int temptime = time - highestTime.first + thisTime;
                double thisMoney = temptime * thisRate;

                // it is possible that "several"
                // higher rate workers beat down the current combination
                // just because they work less, so no if condition here.
                rate = thisRate;
                time = temptime;
                q.pop();
                q.emplace(thisTime, h[i]);
                // end of possibility
                if (thisMoney < money)
                {
                    money = thisMoney;
                }
            }
        }
        return money;
    }
};

double q857()
{
    Solution s;
    vector<int>quality{ 32,43,66,9,94,57,25,44,99,19 };
    vector<int>wage{ 187,366,117,363,121,494,348,382,385,262 };
    int k = 4;
    double result = s.mincostToHireWorkers(quality, wage, k);
    return result;
}