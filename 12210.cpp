#include "bits/stdc++.h"
using namespace std;

int maxNum = 0;
struct comp {
    bool operator()(int a, int b) {
        return (abs(a - maxNum)) < (abs(b - maxNum));
    }
};

int main(int argc, char const *argv[]) {
  int b, s, c = 1;
  while (scanf("%d%d",&b,&s) && b && s) {
    int bach [b];
    int spin [s];
    maxNum = -1;
    for (int i = 0; i < b; ++i) {
      scanf("%d",bach + i);
      maxNum = max(maxNum, bach[i]);
    }
    for (int i = 0; i < s; ++i) {
      scanf("%d",spin + i);
    }

    comp t;
    sort(bach, bach + b, greater<int>());
    sort(spin, spin + s, t);
    if (b <= s) {
      printf("Case %d: 0",c++);
    } else {
      int ans = b - s;
      int l = bach[b-1];
      printf("Case %d: %d %d",c++,ans,l);
    }
    printf("\n");
  }
  return 0;
}
