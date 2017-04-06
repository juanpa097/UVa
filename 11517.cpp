#include "bits/stdc++.h"
#define  INF 1000000
using namespace std;

int dp1[10010][10010];
int dp2[10010][10010];

vector<int> coins;

int dif = -10100;
int numC = 0;


int change(int at, int value, int num) {
  if(at == coins.size()) {
    if(value <= 0) {
      dp1[coins[at]][value] = max(dp1[coins[at]][value], value);
      return dp1[coins[at]][value];
    } else {
      return INF - 1;
    }
  }
  if(dp1[coins[at]][value] == INF)
    dp1[coins[at]][value] = min(change(at + 1, value - coins[at],num + 1), change(at + 1, value,num));
  return dp1[coins[at]][value];
}

int main(int argc, char const *argv[]) {
  memset(dp1, INF, sizeof dp1);
  memset(dp2, 0, sizeof dp2);
  int TC;
  scanf("%d",&TC);
  while(TC--) {
    int value, c;
    scanf("%d",&value);
    scanf("%d",&c);
    coins.clear();
    coins.resize(c);
    dif = -10100;
    numC = 0;
    for(int i = 0; i < c; ++i)
      scanf("%d",&coins[i]);
    // pair<int,int> ans = change(0,value,0);
    cout << change(0,value,0) << endl;
    //printf("%d %d\n", value - dif, numC);

  }
  return 0;
}
