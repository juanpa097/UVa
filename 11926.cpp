#include "bits/stdc++.h"

using namespace std;

<<<<<<< Updated upstream
bool fillNormal (bitset<1001000> &v, int l, int r) {
  if (r - l == 1) {
    if (l+1 < v.size() && !v[l+1]) {
      v.set(l+1);
      return true;
=======
bool fillNormal (bitset<1000000> &v, int l, int r) {
  for (int i = l; i < r && i < v.size(); ++i) {
    if (v.test(i)) {
      //cout << "Conf: " << i << endl;
      return false;
>>>>>>> Stashed changes
    } else {
      return false;
    }
  }
  if (l + 1 < v.size() && !v[l+1] && r - 1 >= 0 && !v[r-1]) {
    for (int i = l; i <= r && i < v.size(); ++i) {
      if (i != l && v.test(i) && i != r) {
        return false;
      } else {
        v.set(i);
      }
    }
  }
  return true;
}

<<<<<<< Updated upstream
bool fillFull (bitset<1001000> &v, int l, int r, int rep){
  for (int i = l; i < v.size(); i+=rep)  {
    if (l + i < v.size() && !fillNormal(v, l + i, r + i)) {
=======
bool fillFull (bitset<1000000> &v, int l, int r, int rep){
  for (int i = 0; i < v.size(); i+=rep) {
    if (!fillNormal(v, l + i, r + i)) {
>>>>>>> Stashed changes
      return false;
    }
  }
  return true;
}


int main(int argc, char const *argv[]) {
  int n,m;

<<<<<<< Updated upstream
  while (scanf("%d%d",&n,&m)) {
    if (n == 0 && m == 0) break;
      bitset<1001000> v;
=======
  while (scanf("%d%d",&n,&m) && (n||m)) {
      bitset<1000000> v;
>>>>>>> Stashed changes
      bool flag = true;
      for (int i = 0; i < n; ++i) {
        int p, k;
        scanf("%d%d", &p,&k);
        if (!fillNormal(v,p,k) && flag) {
          flag = false;
        }
      }
      for (int i = 0; i < m; ++i) {
        int p, k, t;
        scanf("%d%d%d", &p,&k,&t);
        if (!fillFull(v,p,k,t) && flag) {
          flag = false;
        }
      }
      if (!flag) printf("CONFLICT\n");
      else printf("NO CONFLICT\n");
  }
  return 0;
}
