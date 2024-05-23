#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        // m <= n
        int total = m + n;
        bool odd = total & 1;
        int half = total / 2;
        if (m == 0)
        {
            if (odd)
            {
                return nums2[half];
            }
            else
            {
                return double(nums2[half] + nums2[half - 1]) / 2;
            }
        }
        int left = 0, right = m + 1;
        while (true)
        {
            // NB: aless为个数
            // 我大概就不该用什么index，直接用个数aless
            int arightindex = (left + right) / 2 - 1;
            int aless = arightindex + 1;
            int bless = half - aless;
            if (aless == 0)
            {
                // nums1里的数都不在less组里（大！）
                // nums1里的数在中位或是greater组
                // 在中大组里找最小值
                // 和在小组里找最大值
                int acandidate = nums1[0];
                if (odd)
                {
                    int bcandicate = nums2[bless]; // 这不是bless成员
                    return min(acandidate, bcandicate);
                }
                else
                {
                    int bcandidate = nums2[bless - 1]; //bless最大员
                    if (bless < n)
                    {
                        return double(bcandidate + min(acandidate,nums2[bless])) / 2;
                    }
                    else
                    {
                        return double(bcandidate + acandidate) / 2;
                    }
                }
            }
            else if (aless == m)
            {
                // nums1里全是less（小！）
                // 奇数时中位数在对面
                if (nums2[bless] >= nums1[arightindex])
                {
                    int bcandidate = nums2[bless];
                    if (odd)
                    {
                        return bcandidate;
                    }
                    else
                    {
                        // 本质bless和bless-1
                        int b2 = bless == 0 ? nums1[arightindex] : nums2[bless - 1];
                        return double(bcandidate + max(b2, nums1[m - 1])) / 2;
                    }
                }
                else
                {
                    right--;
                }
            }
            else
            {
                int brightindex = bless - 1;
                int abiggest = nums1[arightindex]; // 这都还是less组的
                if (abiggest > nums2[bless]) // bless下表不是less组的
                {
                    right = arightindex + 1;
                    continue;
                }
                int bbiggest = nums2[brightindex]; // 这都还是less组的
                if (bbiggest > nums1[aless])
                {
                    left = arightindex + 1;
                    continue;
                }

                if (odd)
                {
                    return min(nums2[bless], nums1[aless]);
                }
                else
                {
                    return double(max(abiggest, bbiggest) + min(nums2[bless], nums1[aless])) / 2;
                }
            }
        }
        return 0;
    }
};

// A数组与B数组asize bsize
// A数组中在结果中位数左边的数量aless
// B数组中在结果中位数右边的数量bgreat
// aless+agreat = asize
// bless+bgreat = bsize
// aless+bless = (asize+bsize)/2  （中位数左）
// agreat+bgreat = (asize+bsize)/2 （中位数右）
//
class SolutionTemp {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        // OK now m<=n
        int total = m + n;
        int half = total / 2;
        bool odd = total & 1;
        // a数组一个都不用在less区,但如果a数组就有中位数？？？
        if (nums2[0] >= nums1[m - 1])
        {
            int newHalf = half - m;
            if (odd)
            {
                return nums2[newHalf];
            }
            else
            {
                if (newHalf == 0)
                {
                    return double(nums2[0] + nums1[m - 1]) / 2;
                }
                else
                {
                    return double(nums2[newHalf] + nums2[newHalf - 1]) / 2;
                }
            }
        }
        for (int aless = 1; aless < m; aless++)
        {
            int agreat = m - aless;
            int bless = half - aless;
            int bgreat = half - agreat;

            int biggestLessA = nums1[aless - 1];
            int biggestLessB = nums2[bless - 1];
            int biggestLess = max(biggestLessA, biggestLessB);

            int smallestGreatA = nums1[aless];
            int smallestGreatB = nums2[bless];
            int smallestGreat = min(smallestGreatA, smallestGreatB);

            if (smallestGreat >= biggestLess)
            {
                // found
                if (odd)
                {
                    return min(nums1[aless], nums2[bless]);
                }
                else
                {
                    return double(biggestLess + smallestGreat) / 2;
                }
            }
        }
        int bless = half - m;
        if (odd)
        {
            return nums2[bless];
        }
        else
        {
            return double(nums2[bless] + nums2[bless - 1]) / 2;
        }
    }
};

int q4()
{
    Solution s;
    double result = 0;
    vector<int>a{ 3 };
    vector<int>b{ 1,2,4 };
    result = s.findMedianSortedArrays(a, b);
    return 0;
}
