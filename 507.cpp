#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int TC = 1, n, c = 1;
  scanf("%d",&TC);
  while (TC--) {
    scanf("%d",&n);
    --n;
    //int a[] = {4, -5, 4, -3, 4, 4, -4, 4, -5};
    //int a[] = {1, -3, 2, 1, -1};
    //n = 9;
    //n = 5;
    int a[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d",a+i);
    }
    int sum = 0;
    int ans = 0;
    int l = 0;
    int z = 0, h = 0;

    for (int i = 0; i < n; i++) {
      sum +=a[i];
      if (sum > ans || ( (sum == ans) && ( (i - z) > (h - l)) ) ) {
        ans = sum;
        h = i;
        l = z;
      }
      if (sum < 0) {
        sum = 0;
        z = i;
      }
    }
    if (l == -1) l = 0;
    if (ans > 0)
      printf("The nicest part of route %d is between stops %d and %d\n",c++,l+2,h+2);
    else
      printf("Route %d has no nice parts\n",c++);
  }
  return 0;
}
