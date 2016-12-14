#include "bits/stdc++.h"
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long yep (long long k, long long x) {
  long long a = k*x;
  long long b = x - k;
  double ans = double (a) / double (b);
  double fl = floor(ans);
  bool flag = ((fl - ans) >= 0.00);
  if (flag) return (a/b);
  else return -1;

}

int main(int argc, char const *argv[]) {

  long long dp [10001] = {0};

  long long cont = 0;
  long long k;
  while (scanf("%lld",&k) != EOF) {
    cont = 0;
    if (dp[k] == 0) {
      for (long long i = ( (k*k) + k); i >= (2 * k); --i) {
        long long y = yep (k,i);
        if (y != -1 && i >= y && y > 0) {
          ++cont;
        }
      }
      dp[k] = cont;
    } else cont = dp[k];
    printf("%lld\n",cont);
    for (long long i = ( (k*k) + k); i >=  (2 * k); --i) {
      long long y = yep (k,i);
      if (y != -1 && i >= y && y > 0) {
        printf("1/%lld = 1/%lld + 1/%lld\n",k,i,y);
      }
  }
  }
  return 0;
}
