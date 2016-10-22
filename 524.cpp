#include "bits/stdc++.h"
using namespace std;

bool isPrime (int n) {
  if (n == 1 || n == 2) return true;
  int divis = 0;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) ++divis;
    if (divis > 2) return false;
  }
  return true;
}

void solve (int ring[], int n, int idx, bitset<20> & vis) {
  if (idx >= n && isPrime(ring[n-1] + 1)) {
    for (int i = 0; i < n; ++i) {
      printf("%d",ring[i]);
      if (i != n - 1) printf(" ");
    }
    printf("\n");
  }

  for (int i = 2; i <= n; ++i) {
    if (isPrime (ring[idx - 1] + i) && vis[i] == 0) {
      //printf("IDX: %d I: %d\n", idx, i);
      ring[idx] = i;
      vis[i] = 1;
      solve(ring, n, idx + 1, vis);
      //if (solve(ring, n, idx + 1, vis)) return true;
      vis[i] = 0;
    } else {

    }
  }
  //return;
}

int main(int argc, char const *argv[]) {
  int cas = 0;
  int n;
  while (scanf("%d",&n) != EOF) {
    bitset<20> vis;
    int ring [n];
    ring[0] = 1;
    vis[1] = 1;
    ++cas;
    if (cas > 1) printf("\n");
    printf("Case %d:\n",cas);
    solve (ring, n, 1, vis);
  }
  return 0;
}
