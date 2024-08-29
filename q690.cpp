#include <queue>
#include <vector>
using namespace std;
// Definition for Employee.
class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
public:
  int getImportance(vector<Employee *> employees, int id)
  {
    int n = employees.size();
    int leader = 0;
    vector<int> fromID(2001, -1);
    for (int i = 0; i < n; i++) {
      int temp = employees[i]->id;
      fromID[temp] = i;
      if (temp == id) {
        leader = i;
      }
    }
    int result = 0;

    queue<Employee *> q;
    q.push(employees[leader]);
    while (!q.empty()) {
      Employee *current = q.front();
      q.pop();
      result += current->importance;
      for (auto i : current->subordinates) {
        q.push(employees[fromID[i]]);
      }
    }
    return result;
  }
};

int main(int argc, char **argv) { return 0; 
}