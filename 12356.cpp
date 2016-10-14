#include "bits/stdc++.h"
//#include <bits/stdc++.h>

// 1 2 3 4 5 6 7 8 9 10

// 2 3 4 5 6 7 8 9 10 0 right

// 0 1 2 3 4 5 6 7 8 9 left


/*
1 1
1 1
10 4
2 5
6 9
1 1
10 10
5 1
1 1
0 0

*/


using namespace std;

int main () {
  int s, b;
  while (scanf ("%d %d", &s,&b) != EOF) {
    if (s == 0 & b == 0) break;
    int right [100100] = {0};
    int left [100100] = {0};

    for (int i = 1; i <= s; ++i) {
      right[i] = i + 1;
      left[i] = i - 1;
    }

      while (b--) {
        int l, r;
        scanf("%d %d",&l,&r);
        if (left[l] == 0) printf("* ");
        else {
          printf("%d ",left[l]);
        }

        if (right[r] == 0 || right[r] > s) printf("*\n");
        else {
          printf("%d\n",right[r]);
        }

        right[left[l]] = right[r];
        left[right[r]] = left[l];
      }
      printf("-\n");
  }
}
