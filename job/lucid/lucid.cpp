#include <iostream>

using namespace std;

inline int add( int a, int b )
{
  int result = a + b;
  if ( result >= 1000000007 )
    return result % 1000000007;
  
  return result;
}
// Gives how long "ch" will be
// after t transformations
int getLength( char ch, int t )
{
  int distToZ = 'z' - ch;
  if ( t <= distToZ ) {
      return 1;
  }

  t -= distToZ + 1;
  return add( getLength( 'a', t ), getLength( 'b', t ) );
 }

int getTransformedLength(string word, int t) {
  int result = 0;
  for ( int i = 0; i < word.size(); i++ ) {
    result = add( result, getLength( word[ i ], t ) );
  }
  return result;
}

int main()
{
  string str;
  cin >> str;
  int t;
  cin >> t;
  cout << getTransformedLength( str, t ) << endl;
}
