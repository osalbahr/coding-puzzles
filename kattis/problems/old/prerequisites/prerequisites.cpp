#include <iostream>
#include <set>

using namespace std;

bool solve( int k )
{
  set<int> courses;
  int m;
  cin >> m;

  // Read courses
  for ( int i = 0; i < k; i++ ) {
    int course;
    cin >> course;
    courses.insert( course );
    // cout << course << endl;
  }

  // Check each category
  bool isValid = true;
  for ( int i = 0; i < m; i++ ) {
    int c, r;
    cin >> c >> r;
    for ( int j = 0; j < c; j++ ) {
      int current;
      cin >> current;

      if ( r == 0 ) {
        continue;
      }

      if ( courses.count( current ) != 0 ) {
        r--;
      }
    }

    // Did not fulfill this category
    if ( r != 0 ) {
      isValid = false;
    }
  }

  return isValid;
}

int main()
{
  int k;
  while ( cin >> k && k != 0 ) {
    if ( solve( k ) ) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
    // cout << "test" << endl;
  }
}
