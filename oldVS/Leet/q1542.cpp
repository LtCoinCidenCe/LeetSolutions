#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int result = 1;

        unordered_map<int, int>subs;
        subs[0] = -1;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            int cc = 1 << (c - '0');
            last ^= cc; // bitwise XOR
            // int bitNot = cc ^ 1023;
            for (size_t j = 0; j < 10; j++)
            {
                int counterpart = last ^ (1 << j);
                if (subs.find(counterpart) == subs.end())
                {
                    continue;
                }
                int preIndex = subs[counterpart];
                int longOne = i - preIndex;
                result = max(longOne, result);
            }

            if (subs.find(last) == subs.end())
            {
                subs[last] = i;
            }
        }
        if (last==0)
        {
            return n;
        }
        else
        {
            return result;
        }
    }
};

int q1542()
{
    Solution s;
    int result = 0;
    result = s.longestAwesome("373781");
    return result;
}
