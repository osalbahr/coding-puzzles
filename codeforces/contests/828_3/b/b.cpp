#include <iostream>

using namespace std;

void solve()
{
  long long evens = 0;
  int evenC = 0;
  long long odds = 0;
  int oddC = 0;

  int n, q;
  cin >> n >> q;
  for ( int i = 0; i < n; i++ ) {
    int num;
    cin >> num;

    if ( num % 2 == 0 ) {
      evens += num;
      evenC++;
    } else {
      odds += num;
      oddC++;
    }
  }

  for ( int i = 0; i < q; i++ ) {
    int type, x;
    cin >> type >> x;
    evens += ( type == 0 ) * x * evenC;
    odds += ( type == 1 ) * x * oddC;
    cout << evens + odds << endl;

    if ( x % 2 == 1 ) {
      if ( type == 0 ) {
        oddC = evenC + oddC;
        evenC = 0;
      } else {
        evenC = evenC + oddC;
        oddC = 0;
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;
    
  while ( t-- ) {
    
    solve();
  }
}
