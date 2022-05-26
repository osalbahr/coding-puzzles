#include <stdio.h>
#include <stdbool.h>

void updateHigh( int *high, int current )
{
  if ( current <= *high ) {
    *high = current - 1;
  }
}

void updateLow( int *low, int current )
{
  if ( current >= *low ) {
    *low = current + 1;
  }
}


void checkValid( int current, int low, int high )
{
  if ( current < low || current > high ) {
    printf( "Stan is dishonest\n" );
  } else {
    printf( "Stan may be honest\n" );
  }
}

int main()
{
  bool keepGoing = true;
  char str[ 8 ];
  int high = 10;
  int low = 1;
  int current;
  while ( keepGoing ) {
    scanf( "%d", &current);
    
    if ( current == 0 ) {
      break;
    }

    scanf( "%*s%s", str );
    
    switch( str[ 0 ] ) {
      case 'h':
        updateHigh( &high, current );
        break;
      case 'l':
        updateLow( &low, current );
        break;
      default: // case 'o'
        checkValid( current, low, high );
        high = 10;
        low = 1;
    }
  }
}
