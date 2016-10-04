#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  long long a;
  long long b;
  while (scanf("%lld%lld",&a,&b) != EOF) {
    long long c = abs(a - b);
    printf("%lld\n",c);
  }
  return 0;
}
