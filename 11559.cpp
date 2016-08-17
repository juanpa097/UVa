#include "bits/stdc++.h"
//#include <bits/stdc++.h>



int main () {
  int n, b, h, w;
  while (scanf("%d %d %d %d",&n, &b,&h,&w) != EOF) {
    bool can = false;
    int minCost = 60000000;
    while (h--){
      int cost = 0;
      scanf("%d",&cost);
      int total = cost * n;
      for (int i = 0; i < w; i++) {
        int beds = 0;
        scanf("%d",&beds);
        if ((beds >= n) && (total <= b)) {
          can = true;
          if (total < minCost) {
            minCost = total;
          }
        }
      }
    }
    if (can) {
      printf ("%d\n",minCost);
    } else {
      printf("stay home\n");
    }
  }
}
