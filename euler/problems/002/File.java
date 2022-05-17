public class File {

    public static int fibb( int n )
    {
        if ( n == 1 ) {
            return 1;
        }

        if ( n == 2 ) {
            return 2;
        }

        return fibb( n - 2 ) + fibb( n - 1 );
    }

    public static void main(String[] args) {
        // 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
        int total = 0;

        for ( int i = 1, current = fibb( i ); current <= 4000000; current = fibb( i++ ) ) {
            if ( current % 2 == 0 ) {
                total += current;
            }
        }

        System.out.printf( "Expected: %d\n", 2 + 8 + 34 );
        System.out.printf( "Actual: %d\n", total );
    }

}