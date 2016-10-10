#include "bits/stdc++.h"

using namespace std;

bool fillNormal (bitset<1000010> &v, int l, int r) {
  for (int i = l; i <= r && i < v.size(); ++i) {
    if (i != l && v.test(i) && i != r) {
      return false;
    } else {
      v.set(i);
    }
  }
  return true;
}

bool fillFull (bitset<1000010> &v, int l, int r, int rep){
  for (int i = 0; i < v.size(); i+=rep) {
    if (!fillNormal(v, l + i, r + i)) {
      return false;
    }
  }
  return true;
}


int main(int argc, char const *argv[]) {
  int n,m;

  while (scanf("%d%d",&n,&m) && (n||m)) {
      bitset<1000010> v;
      bool flag = true;
      for (int i =0; i < n; ++i) {
        int p, k;
        scanf("%d%d", &p,&k);
        if (!fillNormal(v,p,k) && flag) {
          flag = false;
          break;
        }
      }
      for (int i = 0; i < m && flag; ++i) {
        int p, k, t;
        scanf("%d%d%d", &p,&k,&t);
        if (!fillFull(v,p,k,t) && flag) {
          flag = false;
          break;
        }
      }
      if (!flag) printf("CONFLICT\n");
      else printf("NO CONFLICT\n");
  }
  return 0;
}
