#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k)
  {
    int n = answerKey.size();
    pair<int, int> twindow{0, 0};
    int numberF = 0;
    pair<int, int> fwindow{0, 0};
    int numberT = 0;
    int result = 1;
    for (int i = 0; i < n; i++) {
      const char &cccc = answerKey[i];
      if (cccc == 'T') {
        // twindow
        twindow.second = i;
        int lll = twindow.second - twindow.first + 1;
        result = max(lll, result);

        // fwindow
        fwindow.second = i;
        if (numberT < k) {
          lll = fwindow.second - fwindow.first + 1;
          result = max(lll, result);
          numberT++;
        }
        else {
          const char &oldChar = answerKey[fwindow.first];
          if (oldChar == 'T') {
            fwindow.first += 1;
          }
          else if (oldChar == 'F') {
            do {
              fwindow.first++;
            } while (answerKey[fwindow.first] != 'T');
            fwindow.first++;
          }
        }
      }
      else if (cccc == 'F') {
        // fwindow
        fwindow.second = i;
        int lll = fwindow.second - fwindow.first + 1;
        result = max(lll, result);

        // twindow
        twindow.second = i;
        if (numberF < k) {
          lll = twindow.second - twindow.first + 1;
          result = max(lll, result);
          numberF++;
        }
        else {
          const char &oldChar = answerKey[twindow.first];
          if (oldChar == 'F') {
            twindow.first += 1;
          }
          else if (oldChar == 'T') {
            do {
              twindow.first++;
            } while (answerKey[twindow.first] != 'F');
            twindow.first++;
          }
        }
      }
    }
    return result;
  }
};

int main(int argc, char **argv)
{
  Solution sln;
  string answerKey = "TTTTTFTFFT";
  int k = 2;
  int result = sln.maxConsecutiveAnswers(answerKey, k);
  return 0;
}
