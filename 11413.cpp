#include "bits/stdc++.h"
using namespace std;
bool can (int ves[], int n, int t, int max, int size) {
  int cont = 0;
  int idx = 0;
  for (int i = 0; i < t; ++i) {
    int temp = n;
    while (temp > 0 && cont != max && (idx < size)) {
      temp -= ves[idx];
      if (temp >= 0) {
        cont+= ves[idx++];
      }
    }
    if (cont == max) return true;
  }
  return false;
}

int findAns (int low, int high, int ves[], int m, int n, int sumMax) {
  int mid = 0;
  int ans = 0;
  while (high - low > 1) {
    mid = (high + low) / 2;
    if (can (ves,mid,m,sumMax,n)) {
      ans = mid;
      high = mid;
    } else {
      low = mid;
    }
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int n, m;
  while (scanf("%d%d",&n,&m) != EOF) {
    int max = 0;
    int ves[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d",ves + i);
      max += ves[i];
    }
    int ans = findAns (0, max + 1, ves, m, n, max);
    printf("%d\n",ans);

  }
  return 0;
}
