#include <iostream>

#define REPORT(X) cout << #X << " = " << (X) << endl

using namespace std;

static bool kPeriodic(const string& line, int k)
{
  if (line.size() % k)
    return false;
  
  string init = line.substr(0, k);
  int idx = 0;
  for (size_t i = 0; i < line.size() - k + 1; i += k) {
    string cur = line.substr(i, k);
    for (char ch : cur) {
      if (ch != init[idx]) {
        return false;
      }
      idx = (idx + 1) % k;
    }
    idx = (idx + k - 1) % k;
  }

  return true;
}

int main()
{
  string line;
  getline(cin, line);
  for (size_t i = 1; i <= line.size(); i++) {
    if (kPeriodic(line, i)) {
      cout << i << endl;
      break;
    }
  }
}
