#include <iostream>

using namespace std;

long long fact( long long n )
{
  if ( n == 0 ) {
    return 1;
  }
  
  return n * fact( n - 1 );
}

int main()
{
  int n;
  cin >> n;
  
  long long result = 0;
  long long nFact = fact( n );
  for ( long long i = 2; i <= n; i++ ) {
    result += nFact / ( fact( i ) * fact( n - i ) );
  }
  
  cout << result << endl;
}
