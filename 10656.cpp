#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  while (scanf("%d",&n) && n) {
    bool zero = false;
    bool some = false;
    vector<int> temp;
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d",&t);
      if (t != 0) {
        temp.push_back(t);
        some = true;
      } else {
        zero = true;
      }
    }
    if (zero && !some)
      temp.push_back(0);

    for (int i = 0; i < temp.size(); ++i){
      printf("%d", temp[i]);
      if (i != temp.size() - 1) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
