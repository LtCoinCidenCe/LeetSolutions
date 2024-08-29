#include <iostream>
using namespace std;

int mostSignificantBit(int n)
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

int setBitNumber(int n)
{
  if (n == 0)
    return 0;

  int msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }

  return (1 << msb);
}

// Driver code
int main()
{
  int n = 65;
  cout << setBitNumber(n);
  cout << "\n" << mostSignificantBit(n) << '\n';

  n = ~(int)0; // test for possible overflow
  return 0;
}