#include <iostream>
#include <vector>
#include <numeric>

#include <stdlib.h>
#include <stdbool.h>

using namespace std;
int main()
{
  int g, t, n;
  cin >> g >> t >> n;

  vector<int> w(n);
  for (int i = 0; i < n; i++)
    cin >> w[i];
  
  int remaining = (g - t) * .9;

  int total = accumulate(w.begin(), w.end(), 0);

  cout << remaining - total << endl;
}
