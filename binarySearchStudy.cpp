#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
  vector<int> nums{1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  int target = 2;
  int index = 0;
  while (nums[index] < target) {
    index++;
  }

binary:
  int count = nums.size();
  int step;
  int left = 0;

  while (count > 0) {
    int it = left;
    step = count / 2;
    it += step;
    if (nums[it] > target) {
      left = ++it;
      count -= step + 1;
    }
    else
      count = step;
  }

  auto leftIt = lower_bound(nums.begin(), nums.end(), target);
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  leftIt = ranges::lower_bound(nums, target, greater());
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  leftIt = ranges::lower_bound(nums, target, greater_equal());
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  leftIt = ranges::lower_bound(nums, target, less_equal());
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;

  cout << endl << endl;

  leftIt = ranges::upper_bound(nums, target);
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  auto reversedIt = upper_bound(nums.rbegin(), nums.rend(), target, greater());
  cout << "found: " << !(reversedIt == nums.rend()) << endl;
  cout << "index: " << reversedIt - nums.rbegin() << endl;
  cout << "value: " << *reversedIt << endl;
  leftIt = ranges::upper_bound(nums, target, greater_equal());
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  leftIt = ranges::upper_bound(nums, target, less_equal());
  cout << "found: " << !(leftIt == nums.end()) << endl;
  cout << "index: " << leftIt - nums.begin() << endl;
  cout << "value: " << *leftIt << endl;
  return 0;
}
