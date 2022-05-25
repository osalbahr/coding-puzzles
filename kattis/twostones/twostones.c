#include <stdio.h>

int main()
{
  int input;
  scanf( "%d", &input );

  if ( input % 2 == 1 ) {
    printf( "Alice\n" );
  } else {
    printf( "Bob\n" );
  }
}
