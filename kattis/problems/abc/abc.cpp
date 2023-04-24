#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

int main()
{
  vector<int> v(3);
  for (int i = 0; i < 3; i++)
    cin >> v[i];

  string order;
  cin >> order;

  sort(v.begin(), v.end());
  for (const auto ch : order)
    cout << v[ch - 'A'] << " ";
  cout << endl;
}
