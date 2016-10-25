#include "bits/stdc++.h"
using namespace std;


int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d", &TC);
  while (TC--) {
    long long n;
    scanf("%lld",&n);
    long long coins[n+1];
    coins[0] = 0;
    long long sum = 0;
    long long cont = 0;
    for (long long i = 1; i <= n; ++i) {
      scanf("%lld", coins + i);
      if (sum + coins[i - 1] < coins[i]) {
        sum+= coins[i - 1];
        ++cont;
      }
    }
    printf("%lld",cont);
    printf("\n");
  }
	return 0;
}
