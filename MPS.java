import java.*;
import java.math.BigInteger;
import java.io.*;
import java.util.*;

class Main {

  private static BigInteger max [] = new BigInteger[110];
  private static BigInteger min [] = new BigInteger[110];
  private static BigInteger A [] = new BigInteger[110];

  private static int N;


  private static BigInteger mps() {
    BigInteger ans = A[0];
    max[0] = min[0] = ans;
    BigInteger zero = new BigInteger("0");

    for (int i = 1; i < N; ++i) {
      if (A[i].compareTo(zero) == 1) {
        BigInteger aMult = A[i].multiply(max[i - 1]);
        BigInteger bMult = A[i].multiply(min[i - 1]);
        max[i] = A[i].max(aMult);
        min[i] = A[i].min(bMult);
      } else {
        BigInteger aMult = A[i].multiply(min[i - 1]);
        BigInteger bMult = A[i].multiply(max[i - 1]);
        max[i] = A[i].max(aMult);
        min[i] = A[i].min(bMult);
      }

      ans = ans.max(max[i]);
    }

    return ans;

  }

  public static void main(String args[]) throws Exception {
    BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
    String line;
    while ((line = br.readLine()) != null ) {
      StringTokenizer st = new StringTokenizer(line);
      int i = 0;
      while (st.hasMoreTokens()) {
        A[i++] = new BigInteger(st.nextToken());
      }
      N = i - 1;
      System.out.println(mps());
    }

  }
}
