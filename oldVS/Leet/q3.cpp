#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int windowLength = 0;
        int start = 0;
        int end = 0;
        unordered_set<char>window;
        while (true)
        {
            if (end >= s.size())
            {
                break;
            }
            // try insert s[end]
            char c = s[end];
            auto noChar = window.insert(c);
            if (!noChar.second)
            {
                for (int i = start; i < end; i++)
                {
                    window.erase(s[i]);
                    if (s[i] == c)
                    {
                        start = i + 1;
                        break;
                    }
                }
            }
            else
            {
                end++;
            }
            windowLength = window.size();
            result = result > windowLength ? result : windowLength;
        }
        return result;
    }
};

int q3()
{
    Solution s;
    int result = s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}
