#include "bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;

int main () {
  int s, b;
  while (scanf ("%d %d", &s,&b) != EOF) {
    if (s == 0 & b == 0) break;
    vector<bool> sol(s+2,true);
    sol[0] = false;
    sol[sol.size()-1] = false;
    while (b--) {
      int l, r;
      scanf("%d %d",&l,&r);
      for (int i = l; i <= r; i++) sol[i] = false;
      int lans = 0;
      int rans = s + 2;
      for (int i= l-1; i >= 0; i--) {
        if (sol[i]) {
          lans = i;
          break;
        }
      }
      for (int i = r+1; i < sol.size(); i++) {
        if (sol[i]) {
          rans = i;
          break;
        }
      }

      if (lans == 0) printf("* ");
      else printf("%d ",lans);

      if (rans == (s+2)) printf("*");
      else printf("%d",rans);
      printf("\n");
    }
    printf("-\n");
  }
}
