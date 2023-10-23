#include <iostream>

#include <cmath>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

void solve(int r, double s)
{
  double n = r * (s + .16);
  double d = .067;
  double v = sqrt(n/d);
  
  int ans = v;
  if (v - ans > 0.5)
    ans++;
  
  cout << ans << endl;
}

int main()
{
  int r;
  double s;
  while (cin >> r >> s) {
    solve(r, s);
  }
}
