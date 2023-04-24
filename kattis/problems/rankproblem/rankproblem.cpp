#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

#include <cstdio>
#include <cassert>

#define REPORT(X)// cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

// static void printList(list<int> ordered)
// {
//   for (const auto& val : ordered) {
//     cout << val << " ->";
//   }
//   cout << endl;
// }


// i beat j
static void solve(list<int>& order, int i, int j)
{
  // remove j
  for ( auto it = order.begin(); it != order.end(); it++ ) {

    // Special case: i is already better than j
    if (*it == i) {
      return;
    }

    if (*it == j) {
      order.erase(it);
      break;
    }
  }

  // move j after (behind) i
  for ( auto it = order.begin(); it != order.end(); it++ ) {
    if (*it == i) {
      order.insert(++it, j);
      return;
    }
  }

  REPORT(i);
  REPORT(j);
  exit(1);
}

static void printOrder(const list<int>& order)
{
  for (const auto& val : order)
    cout << "T" << val << " ";
  cout << endl;
}

int main()
{
  int n, m;
  cin >> n >> m;

  list<int> order;
  for (int i = 0; i < n; i++)
    order.push_back(i + 1);
  
  // printList(order);
  
  string line;
  getline(cin, line);


  while (m--) {
    getline(cin, line);
    int i, j;
    sscanf(line.c_str(), "T%d T%d", &i, &j);

    REPORT(i);
    REPORT(j);
    solve(order, i, j);
    // printList(order);
  }

  printOrder(order);
}
