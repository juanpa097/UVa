#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while (TC--) {
    unsigned long long a, b;
    cin >> a >> b;
    if (a > b) printf(">\n");
    if (a < b) printf("<\n");
    if (a == b) printf("=\n");
  }
  return 0;
}
