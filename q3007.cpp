#include <algorithm>
#include <vector>
using namespace std;

int mostSignificantBit(long long n)
{
  if (n == 0)
    return 0;

  int msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }

  return msb;
}

class Solution {
public:
  long long whichBitContributionToAccu(long long num, int offset)
  {
    long long falseNum = num + 1;
    long long period = 2ll << offset;
    long long periodTimes = falseNum / period;
    long long result = periodTimes * period / 2;
    long long remaining = falseNum % period;
    return result + max(0ll, remaining - period / 2);
  }
  long long calculateAccu(long long num, int x)
  {
    long long result = 0;
    int targetBit = x;
    int msb = mostSignificantBit(num);
    for (int i = 0;; i++) {
      int offset = targetBit - 1;
      if (offset > msb)
        break;

      result += whichBitContributionToAccu(num, offset);
      targetBit += x;
    }
    return result;
  }
  long long findMaximumNumber(long long k, int x)
  {
    long long l = 0;
    long long r = (2 * k) << x;
    while (l < r) {
      long long num = (l + r + 1) / 2;
      long long accu = calculateAccu(num, x);
      if (accu > k) {
        r = num - 1;
      }
      else {
        l = num;
      }
    }
    return l;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  long long k = 1;
  int x = 5;
  long long result = sln.findMaximumNumber(k, x);
  return 0;
}

/*
dp[num]=accumulatedPrice;
        firstbit to accu num+1/2 period is 2;
        secondbit to accu num+1/2 period is 4;
        thirdbit to accu num+1/2 period is 8;
        if not full period,
        get period times / 2 + max(0,remaining - period/2);

        num=2**i-1;
        num->accu
        as 2**i get simple accu.

        num==7
        8==2**3;
        8falseNum*3everybit/2(flippingbit);

        16falseNum*4/2;

        16falseNum*2/2; if x==2;

        64falseNum*6/2;
        log
        64falseNum*3/2; if x==2;

        64falseNum*2/2; if x==3;
        if x>1 accu(x)<accu(x==1)/x;

        fullbits=log(falseNum)/log(2);

        accu == falseNum*msb/x/2;

        falseNum=accu*2*x/fullBits;
        =accu*2*x*log(2)/log(falseNum) == accu*2*x/msb;

        falseNum*log(falseNum)=accu*2*x;
*/