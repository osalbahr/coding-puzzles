#include <iostream>
#include <string>

using namespace std;

int toValue( char number, bool isDom )
{
    switch ( number ) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            if ( isDom ) return 20;
            return 2;
        case 'T':
            return 10;
        case '9':
            if ( isDom ) return 14;
            return 0;
        case '8':
        case '7':
            return 0;
    }
    
    return -1;
}

int main()
{
    int hands;
    char dominant;
    cin >> hands >> dominant;
    hands *= 4;
    
    int total = 0;
    while ( hands-- ) {
        string current;
        cin >> current;
        total += toValue( current[ 0 ], current[ 1 ] == dominant );
    }
    cout << total << endl;
}
