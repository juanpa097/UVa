/*
3 2 5
3 5 7
2 1 2
2 2 1

3
2
1
1
*/

#include "bits/stdc++.h"
#define DEBUG cout <<
using namespace std;

int foo (int n, int a, int b) {
  int p = 1 << n;
  int maxA = max(a,b);
  int maxB = min(a,b);
  int mitad = p / 2;
  if (maxB <= mitad && maxA > mitad) return n;
  else {
    int retA = a % (p / 2);
    int retB = b % (p / 2);
    if (retA == 0) retA = p / 2;
    if (retB == 0) retB = p / 2;
    return foo (n-1, retA, retB);
  }
}

int main(int argc, char const *argv[]) {
  int n, a, b;
  while (scanf("%d%d%d",&n,&a,&b) != EOF) {
    int res = foo (n,a,b);
    printf("%d\n",res);
  }
  return 0;
}
