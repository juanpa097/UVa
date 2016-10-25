#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int b, s, c = 1;
  while (scanf("%d%d",&b,&s)) {
    int bach [b];
    int spin [s];
    int temp;
    for (int i = 0; i < b; ++i) {
      scanf("%d",bach + i);
    }
    for (int i = 0; i < s; ++i) {
      scanf("%d",spin + i);
    }
    sort(spin, spin + s);
    sort(bach, bach + b);

    bitset<10010> vB;
    bitset<10010> vS;
    int m = 0;
    for (int i = b - 1; i >= 0; --i) {
      pair<int,int> p (10010, 10010);
      int sp;
      bool marr = false;
      for (int j = 0; j < s; ++j) {
        if (abs(bach[i] - spin[j]) < p.first && vS[spin[j]] == 0) {
          p.first = (abs(bach[i] - spin[j]));
          p.second = bach[i];
          sp = spin[j];
          marr = true;
        }
      }
      if (marr) {
        vB[p.second] = 1;
        vS[sp] = 1;
        ++m;
      }
    }
    if (m - b == 0)
      printf("Case %d: %d\n",c++,0);
    else {
      int ans;
      for (int i = 0; i < b; ++i) {
        if (vB[bach[i]] == 0) {
          ans = bach[i];
          break;
        }
      }

      printf("Case %d: %d %d\n",c++,b-m, ans);
    }

  }
  return 0;
}
