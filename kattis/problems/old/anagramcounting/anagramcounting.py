import math
import sys

def solve( s ):
    myDict = {}
    for i in range( len( s ) ):
        c = s[ i ]
        if ( c not in myDict ):
            myDict[ c ] = 1
        else:
            myDict[ c ] = myDict[ c ] + 1
    result = math.factorial( len( s ) )
    for x in myDict.values():
        result = result // math.factorial( x )
    
    return result

# print( solve( input() ) )

for line in sys.stdin:
    print( int(solve( line.split()[0])) )
