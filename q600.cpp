#include <unordered_map>
#include <vector>
using namespace std;

class SolutionOld {
public:
  vector<bool> bits;
  // offset start by 0, require n > 0
  int findHighestOne(int n)
  {
    bits.clear();
    int i = 0;
    do {
      bits.push_back(n & 1);
      if (n == 1) {
        break;
      }
      n = n >> 1;
      i++;
    } while (n != 1);
    bits.push_back(n & 1);
    return i;
  }

  int findIntegers(int n)
  {
    if (n < 3)
      return n + 1;
    int highestOffset = findHighestOne(n);
    // int slots = highestOffset + 1;
    // key为最高位offset，正数代表左侧填0，负数代表左侧填1。value是前部完成数量
    unordered_map<int, int> mem;
    mem[highestOffset] = 1;  // try fill 0
    mem[-highestOffset] = 1; // try fill 1
    // int number = 1 << highestOffset;

    bool escape = false;
    for (int i = 0; i < highestOffset - 1; i++) {
      // try fill 0 (always ok)
      int localOffset = highestOffset - i - 1;
      mem[localOffset] = mem[highestOffset - i] + mem[-(highestOffset - i)];

      if (bits[localOffset] && bits[localOffset + 1])
        escape = true;
      // try fill 1
      if (escape || bits[localOffset] || bits[localOffset + 1])
        mem[-localOffset] = mem[highestOffset - i];
      else
        mem[-localOffset] = mem[highestOffset - i] - 1;
    }

    int result = mem[1] * 2 + mem[-1];
    if (!(escape || bits[0] || bits[1]))
      result -= 1;
    return result;
  }
};

// with vector memory
class Solution {
public:
  vector<bool> bits;
  // offset start by 0, require n > 0
  int findHighestOne(int n)
  {
    bits.clear();
    int i = 0;
    do {
      bits.push_back(n & 1);
      if (n == 1) {
        break;
      }
      n = n >> 1;
      i++;
    } while (n != 1);
    bits.push_back(n & 1);
    return i;
  }

  int findIntegers(int n)
  {
    if (n < 3)
      return n + 1;
    int highestOffset = findHighestOne(n);
    int doubleMemory = highestOffset + highestOffset + 1;
    // int slots = highestOffset + 1;
    // index为offset，使用doubleMemory时填入-offset代表填入1
    vector<int> mem(doubleMemory, 0);
    mem[highestOffset] = 1;                // try fill 0
    mem[doubleMemory - highestOffset] = 1; // try fill 1
    // int number = 1 << highestOffset;

    bool escape = false;
    for (int i = 0; i < highestOffset - 1; i++) {
      // try fill 0 (always ok)
      int localOffset = highestOffset - i - 1;
      mem[localOffset] = mem[highestOffset - i] + mem[doubleMemory - (highestOffset - i)];

      if (bits[localOffset] && bits[localOffset + 1])
        escape = true;
      // try fill 1
      if (escape || bits[localOffset] || bits[localOffset + 1])
        mem[doubleMemory - localOffset] = mem[highestOffset - i];
      else
        mem[doubleMemory - localOffset] = mem[highestOffset - i] - 1;
    }

    int result = mem[1] * 2 + mem[doubleMemory - 1];
    if (!(escape || bits[0] || bits[1]))
      result -= 1;
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  int result = sln.findIntegers(8);
  return 0;
}
