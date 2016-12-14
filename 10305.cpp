#include "bits/stdc++.h"
using namespace std;

vector < vector <int> > AdjList;


void dfs(int v, vector<int> & ts, vector <bool> & visited) {
  for (int i = 0; i < AdjList[v].size(); ++i) {
    int t = AdjList[v][i];
    if (visited[t] == false)
      dfs(t, ts, visited);
  }
  visited[v] = true;
  ts.insert(ts.begin(), v + 1);
}

int main(int argc, char const *argv[]) {
  int n, m;
  while (scanf("%d %d", &n,&m)) {
    if (n == 0 && m == 0) break;
    AdjList.clear();
    AdjList.resize(n);
    for (int i = 0; i < m; ++i) {
      int j, k;
      scanf("%d%d", &j,&k);
      AdjList[j - 1].push_back(k - 1);
    }

    vector<int> ts;
    vector <bool> visited(n,false);
    for (int i = 0; i < n; ++i)
      visited[i] = false;

    for (int i = 0; i < n; ++i) {
      if (visited[i] == false)
        dfs(i, ts, visited);
    }

    printf("%d", ts[0]);
        for (int i = 1; i < ts.size(); i++)
            printf(" %d", ts[i]);
        printf("\n");

  }
  return 0;
}
