#include <iostream>

using namespace std;

void solve()
{
    int k;
    cin >> k;
    int result = -( k - 1 );
    while ( k-- ) {
        int n;
        cin >> n;
        result += n;
    }
    cout << result << endl;
}

int main()
{
  int n;
  cin >> n;
  while ( n-- ) {
      solve();
  }
}
