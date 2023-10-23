#include <iostream>
#include <vector>
#include <list>
#include <cassert>

#define REPORT(X)// cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

static void printList(list<int> ordered)
{
  // for (const auto& val : ordered) {
  //   cout << val << " ->";
  // }
  // cout << endl;

  list<int> cpy = ordered;
  cpy.sort();
  assert(cpy == ordered);
}

int countSteps(list<int>& ordered, int insertVal)
{
  REPORT(insertVal);

  int steps = 0;
  for (auto it = ordered.rbegin(); it != ordered.rend(); it++) {
    if (*it > insertVal)
      steps++;
    else
      break;
  }

  auto pos = ordered.begin();
  advance(pos, ordered.size() - steps);
  ordered.insert(pos, insertVal);

  REPORT(steps);
  REPORT(ordered.size());
  printList(ordered);
  return steps;
}

int solve(const vector<int>& heights)
{  
  list<int> ordered;
  
  int total = 0;
  for (int i = 0; i < 20; i++) {
    total += countSteps(ordered, heights[i]);
  }
  
  return total;
}

int main()
{
  int p;
  cin >> p;
  for (int i = 0; i < p; i++) {
    int k;
    cin >> k;

    vector<int> heights(20);
    for (int j = 0; j < 20; j++)
      cin >> heights[j];

    int ans = solve(heights);
    cout << k << " " << ans << endl;
  }
}
