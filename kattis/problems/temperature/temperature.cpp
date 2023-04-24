#include <iostream>

using namespace std;

// Input consists of two space-separated integers, X and Y.
// X is the point on B where A is zero.
// Y is the number of degrees in B that equal a change of a single degree in A.
void solve(double x, double y)
{
  // Same slope
  if (y == 1) {
    // Same intercept
    if (x == 0) {
      cout << "ALL GOOD" << endl;
    } else {
      cout << "IMPOSSIBLE" << endl; // divide by zero
    }
    return;
  }

  // X is the point on B where A is zero.
  // X=32 is the point on B=F where A=C is zero.
  // F = 9/5 C + 32
  // Y=9/5 is the number of degrees in B=F that equal a single degree in A=C
  // F = Y * C + X
  // ? = Y * ? + X
  // ? - Y * ? = X
  // ? = X / (1 - Y)
  double sol = x / (1 - y);
  printf("%.6f\n", sol);
}

int main()
{
  double x, y;
  cin >> x >> y;
  solve(x, y);
}
