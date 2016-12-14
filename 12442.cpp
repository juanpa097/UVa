#include "bits/stdc++.h"
using namespace std;

vector < vector<int> > adj;
bitset<50010> marked;

int maxD;
int ans = 0;

int vans = -1;
void dfs (int v, int d) {
  marked[v] = 1;
  for (int i = 0; i < adj[v].size(); ++i) {
    int n = adj[v][i];
    if (!marked[n]) {
      maxD = max(maxD, d);
      dfs(n, d + 1);
    } else {
      if (maxD > ans) {
        ans = maxD;
        vans = v;
      }
      break;
    }
  }
}


int main(int argc, char const *argv[]) {
  int TC, c = 1, N,u,v;

  scanf("%d",&TC);

  while (TC--) {
    scanf("%d", &N);
    adj.clear();
    adj.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &u,&v);
      adj[u-1].push_back(v-1);
    }

    // for (int i = 0; i < adj.size(); ++i) {
    //   for (int j = 0; j < adj[i].size(); ++j) {
    //     cout << adj[i][j] + 1<< " ";
    //   }
    //   cout << "\n";
    // }



    //for (int i = 0; i < N; ++i) {
      marked.reset();
      maxD = 0;
      dfs(0, 0);
    //}
    printf("Case %d: %d\n",c++,vans + 1);
  }

  return 0;
}
