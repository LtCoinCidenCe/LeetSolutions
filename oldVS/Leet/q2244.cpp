#include<vector>
#include<map>
#include<unordered_map>
#include<set>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        size_t n = tasks.size();
        unordered_map<int, int>times;
        int result = 0;
        bool fine = true;
        for (size_t i = 0; i < n; i++)
        {
            int taskNo = tasks[i];
            auto found = times.find(taskNo);
            if (found == times.end())
            {
                times.emplace(taskNo, 1);
            }
            else
            {
                found->second++;
                if (found->second == 3)
                {
                    result++;
                }
                if (found->second == 6)
                {
                    result++;
                    found->second = 3;
                }
            }
        }

        for (auto it = times.begin(); it != times.end(); it++)
        {
            if (it->second == 1)
            {
                return -1;
            }
            else if (it->second == 3)
            {
                result--;
            }
        }
        result += times.size();
        return result;
    }
};
