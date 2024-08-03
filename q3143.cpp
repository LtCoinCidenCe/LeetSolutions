#include <ranges>
#include <algorithm>
#include <vector>
#include <ranges>
using namespace std;

class Solution
{
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        int n = points.size();
        vector<pair<int, char>> pnt;
        pnt.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int dian = max(abs(points[i][0]), abs(points[i][1]));
            char letter = s[i];
            pnt.emplace_back(dian, letter);
        }
        ranges::sort(pnt);

        vector<bool> slots(26, false);
        int result = 0;
        for (int i = 0; i < n;)
        {
            pair<int, char> &dian = pnt[i];
            int j;
            for (j = i; j < n; j++)
            {
                pair<int, char> &wai = pnt[j];
                if (wai.first != dian.first)
                {
                    break;
                }
                int indexOfChar = int(wai.second - 'a');
                if (slots[indexOfChar])
                {
                    return result;
                }
                slots[indexOfChar] = true;
            }
            result += j - i;
            i = j;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution sln;
    vector<vector<int>> points{{1, 1}, {-1, -2}, {-2, 1}};
    string s = "abb";

    int result = sln.maxPointsInsideSquare(points, s);
    return 0;
}
