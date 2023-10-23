import java.math.BigInteger;
import java.util.Scanner;

public class character {
  static BigInteger fact( BigInteger n )
  {
    if ( n.equals(0) ) {
      return BigInteger.valueOf(1);
    }
    
    return n.multiply( fact( n.subtract(BigInteger.valueOf(1)) ));
  }

  public static void main(String[] args) {
    BigInteger n;

    Scanner sc = new Scanner( System.in );
    int input = sc.nextInt();
    n = BigInteger.valueOf( input );
    BigInteger nFact = fact( n );
    BigInteger result = BigInteger.valueOf(0);
    for ( int i = 2; i <= input; i++ ) {
      result = result.add( nFact.divide( fact( BigInteger.valueOf( i ) ).multiply( fact( n.subtract(BigInteger.valueOf(i))) )) );
    }
    
    System.out.println(result);
  }
}
