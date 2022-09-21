#include <iostream>

using namespace std;

int getTransformedLength(string word, int t) {
  while ( t-- ) {
    for ( int i = 0; i < word.size(); i++ ) {
      char ch = word[ i ];
      if ( ch == 'z' ) {
        word.replace( i, 1, "ab" );
      } else {
        word[ i ] = ch + 1;
      }
    }
  }
  return word.size();
}

int main()
{
  string str;
  cin >> str;
  int t;
  cin >> t;
  cout << getTransformedLength( str, t ) << endl;
}
