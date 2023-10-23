#include <iostream>
#include <string>

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int result = 1;
    for ( int i = 0; i < 4; i++ )
        if ( s1[ i ] != s2[ i ] )
            result *= 2;
    cout << result << endl;
}
