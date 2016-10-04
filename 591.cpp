#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int c = 1;
  int n;
  while (scanf("%d",&n) && n) {
    vector<int> v (n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int num;
      scanf("%d",&num);
      v[i] = num;
      sum += num;
    }
    int h = sum / n;
    int cont = 0;
    int del = 0;
    for (int i = 0; i < n; ++i) {
      del = v[i] - h;
      if (del < 0) cont += abs(del);
    }
    printf("Set #%d\n",c++);
    printf("The minimum number of moves is %d.\n\n",cont);
  }
  return 0;
}
