#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
        {
            return false;
        }
        ostringstream oss;
        oss << x;
        string s = oss.str();
        int n = s.size();
        for (int i = 0; i < n/2; i++)
        {
            if (!(s[i] == s[n - 1 - i]))
                return false;
        }
        return true;
    }
};

int q9()
{
    Solution s;
    s.isPalindrome(90);
    return 0;
}