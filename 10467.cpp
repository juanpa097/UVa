#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int n, q;
  int c = 1;
  while (scanf("%d",&n), n) {
    int nums [n];

    for (int i = 0; i < n; ++i) {
      scanf("%d", nums + i);
    }

    scanf("%d",&q);

    printf("Case %d:\n",c++);
    for (int i = 0; i < q; ++i) {
      int m;
      scanf("%d",&m);
      int dif = (1<<30);
      int ans = 0;

      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) {
          int sum = nums[j] + nums[k];
          if (abs(m - sum) < dif && j != k) {
            dif = abs(m - sum);
            ans = sum;
          }
        }
      printf("Closest sum to %d is %d.\n",m,ans);


    }

  }
  return 0;
}
