#include "bits/stdc++.h"
using namespace std;

/*
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
0

*/

vector < vector<int> > adj;
vector <bool> visited;
int vis;

void dfs (int v) {
  for (int i = 0; i < adj[v].size(); ++i) {
    int n = adj[v][i];
    if (!visited[n]) {
      visited[n] = true;
      ++vis;
      dfs(n);
    }
  }
}

void ans (int v) {
  dfs(v);
  vis = visited.size() - vis;
  printf("%d", vis);
  for (int i = 0; i < visited.size(); ++i) {
    if (!visited[i])
      printf(" %d", i+1);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int N;
  while (scanf("%d",&N) && N != 0) {
    adj.clear();
    adj.resize(N);
    int i;
    while (scanf("%d",&i) && i != 0) {
      int k;
      while (scanf("%d",&k) && k != 0) {
        adj[i-1].push_back(k-1);
      }
    }
    int v;
    scanf("%d",&i);
    for (int j = 0; j < i; ++j) {
      scanf("%d",&v);
      visited.clear();
      visited.assign(N, false);

      vis = 0;
      ans(v-1);
    }
  }
  return 0;
}
