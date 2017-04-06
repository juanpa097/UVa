#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {

  int TC;
  scanf("%d",&TC);
  for (int i = 0; i < TC; ++i) {
    int a[5];
    for (int i = 0; i < 5; ++i) {
      int temp;
      scanf("%d",&temp);
      a[i] = temp;
    }
    bool can = true;
    for (int i = 0; i < 4; ++i) {
      if (a[i] + 1 != a[i +1]) {
        can = false;
        break;
      }
    }
    if (can) printf("Y\n");
    else printf("N\n");

  }
  return 0;
}
