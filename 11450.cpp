#include "bits/stdc++.h"
using namespace std;


int TC,M,C;
int price[25][25];
int memo[210][25];
int score (int money, int g) {
  if (money < 0) return (1 << 31);
  if (g == C) return M - money;
  int ans = -1;
  if (memo[money][g] != -1) return memo[money][g];
  for (int model = 1; model <= price[g][0]; ++model) {
    ans = max(score(money - price[g][model], g + 1), ans);
  }
  memo[money][g] = ans;
  return ans;
}

int main(int argc, char const *argv[]) {
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d%d", &M, &C);
    for (int i = 0; i < C; ++i) {
      scanf("%d",&price[i][0]);
      for (int j = 1; j <= price[i][0]; ++j)
        scanf("%d",&price[i][j]);
    }
    memset(memo, -1 ,sizeof memo);
    int ans = score(M,0);
    if (ans < 0) printf("no solution\n");
    else printf("%d\n",ans);
  }
  return 0;
}
