#include "bits/stdc++.h"
using namespace std;

vector < int > adj;
bitset<50010> marked;

int maxD;
int ans = 0;

int dfs (int v, int ans) {
  if (!marked[v]) marked[v] = 1;
  else return ans;
     

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
      adj[u-1] = v-1);
    }

  }

    // for (int i = 0; i < adj.size(); ++i) {
    //   for (int j = 0; j < adj[i].size(); ++j) {
    //     cout << adj[i][j] + 1<< " ";
    //   }
    //   cout << "\n";
    // }



    //}
    printf("Case %d: %d\n",c++,vans + 1);
  }

  return 0;
}
