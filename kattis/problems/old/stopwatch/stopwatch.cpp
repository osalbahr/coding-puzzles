#include <iostream>

using namespace std;

// #define REPORT( X ) cerr << #X << " = " << X << endl

int main()
{
  int n;
  cin >> n;

  if (n % 2) {
    cout << "still running" << endl;
    return 0;
  }

  int total = 0;
  n /= 2;
  while (n--) {
    int a, b;
    cin >> a >> b;
    REPORT(a);
    REPORT(a);
    total += b - a;
  }

  cout << total << endl;
}
