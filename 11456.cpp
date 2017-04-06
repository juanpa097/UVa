#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
vi A;
vi dp;
vi dp1;

void LIC() {
  int i = 0, j = 1;
  while(j < A.size()) {
    if(A[i] < A[j]) dp[j] = max(dp[j], dp[i] + 1);
    ++i;
    if(i == j) ++j, i = 0;
  }
}

void LDC() {
  int i = 0, j = 1;
  while(j < A.size()) {
    if(A[i] > A[j]) dp1[j] = max(dp1[j], dp1[i] + 1);
    ++i;
    if(i == j) ++j, i = 0;
  }
}

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while(TC--) {
    int n;
    A.clear();
    dp.clear();
    dp1.clear();
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d",&a);
      A.push_back(a);
      dp.push_back(1);
      dp1.push_back(1);
    }
    LIC();
    LDC();
    int ans = -1;

    // for(int i = 0; i < dp.size(); ++i) {
    //   cout << dp1[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < dp.size(); ++i) {
    //   cout << dp[i] << " ";
    // }
    // cout << endl;
    for(int i = 0; i < dp.size(); ++i) {
      ans = max(dp[i] + dp1[i] - 1, ans);
    }
    printf("%d\n", max(ans, 0));
}

  return 0;
}
