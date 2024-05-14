#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        int b = n;
        char result[32];
        int length = 0;
        string strResult = "";
        strResult.reserve(32);
        for (int i = 0; i < 32; i++)
        {
            int before = b >> i;
            int bit = before & 1; // could use bitwise or to quickly get remaining 1.
            int bigness = 1 << i;
            if (before == 0)
            {
                length = i;
                break;
            }
            if (i % 2 == 1)
            {
                // minus
                if (bit==1)
                {
                    result[i] = '1';
                    b += bigness;  // sum bi-bignessi = n
                }
                else
                {
                    result[i] = '0';
                }
            }
            else
            {
                // positive
                if (bit==1)
                {
                    result[i] = '1';
                }
                else
                {
                    result[i] = '0';
                }
            }
        }
        for (int i = length - 1; i >= 0; i--)
        {
            strResult += result[i];
        }
        if (strResult=="")
        {
            strResult = '0';
        }
        return strResult;
    }
};

int q1017()
{
    int a = 8 >> 1;
    int b = 9 >> 0;
    int bigness = 1 << 4;
    Solution s;
    for (size_t i = 0; i < 9; i++)
    {
        cout << i << '\t' << s.baseNeg2(i) << endl;
    }
    cout << 1000000000 << '\t' << s.baseNeg2(1000000000) << endl;
    return 0;
}
