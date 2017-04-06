#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while (TC--) {
    int a, b;
    scanf("%d%d",&a,&b);
    a = a/3;
    b = b /3;
    printf("%d\n",a*b);
  }
  return 0;
}
