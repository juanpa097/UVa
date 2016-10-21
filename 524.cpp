#include "bits/stdc++.h"
using namespace std;

bool isPrime (int n) {
  int cont = 0;
  if (n == 2 ||n == 1) return true;
  for (int i = 2; i <= n; ++i) {
    if (n % i == 0) ++cont;
    if (cont >= 2) return false;
  }
  return true;
}

bool solve (vector<int> &v, int n, int idx, bitset<17> &s) {
  if (idx > v.size() && isPrime(v[0] && v[n-1]))
    return true;
  for (int i = 1; i <= n; ++i) {
    if (isPrime(i + v[idx - 1]) && s[i] == 0) {
      v[idx] = i;
      //printf("In: %d\n",i);
      s[i] = 1;
      printf("IDX: %d   I: %d\n",idx, i);
      if (solve(v,n,idx + 1,s)) {
        return true;
      }
      s[i] = 0;

      //printf("Out: %d\n",i);
    }
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n;
  while (scanf("%d",&n) != EOF) {
    vector<int> v(n);
    v[0] = 1;
    bitset<17> s;
    s[1] = 1;
    solve(v,n,1,s);
    for (int i = 0; i < v.size(); ++i) {}
      //printf("%d ",v[i]);
    //printf("\n");
  }
  return 0;
}
