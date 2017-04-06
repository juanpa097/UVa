#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int coinType[] = {1,5,10,25,50};
int N = 5;

ll dp[30010][5];

ll ways(int type, int value) {
  if (value == 0) return 1;
  if (value < 0) return 0;
  if (type == N) return 0;
  if (dp[value][type] == - 1)
    dp[value][type] = ways(type + 1, value) + ways(type, value - coinType[type]);
  return dp[value][type];
}

int main(int argc, char const *argv[]) {
  int n;
  memset(dp,-1, sizeof dp);
  while (scanf("%d",&n) != EOF) {
    ll w = ways(0,n);
    if (w > 1)
      printf("There are %lld ways to produce %d cents change.\n",w, n);
    else
      printf("There is only 1 way to produce %d cents change.\n",n);
  }
  return 0;
}
