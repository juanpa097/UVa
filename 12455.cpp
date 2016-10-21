#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while (TC--) {
    int n;
    int p;
    scanf("%d",&n);
    scanf("%d",&p);
    int l[p];
    for (int i = 0; i < p; i++) {
      scanf("%d",&l[i]);
    }
    bool sol = false;
    //unsigned int t = 0;
    if (n == 0) {
      printf("YES\n");
    } else {
      for (int i = 0; i < (1 << p); ++i) {
        int temp = 0;
        for (int j = 0; j < p; ++j){
          if (i & (1 << j)) {
            temp += l[j];
            //cout << l[j] << " ";
          }
        }
        //cout << endl;
        if (temp == n) {
          sol = true;
          break;
        }
      }
      if (sol) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}
