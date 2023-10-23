#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <numeric>

#include <cstdio>

#define REPORT(X) cout << __LINE__ << " " << #X << " = " << X << endl

using namespace std;

int main()
{
  int n, d;
  scanf("%d/%d", &n, &d);

  // subtract 32
  n -= 32 * d;

  // multiply by 5/9
  n *= 5;
  d *= 9;

  // simplify
  int g = gcd(n, d);
  n /= g;
  d /= g;
  printf("%d/%d\n", n, d);
}
