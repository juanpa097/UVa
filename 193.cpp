#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  int cas = 1;
  while (TC--) {
    int m, n;
    scanf("%d%d", &m,&n);
    std::vector< vector <int> > adj(m+1);
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    set <int> wh;
    set <int> bl;

    set <int> ans;

    int maxS = -1;
    for (int i = 1; i <= m; ++i) {
      bitset<101> visited;
      queue<int> bfs;
      bfs.push(i);
      bl.insert(i);
      bool isB = true;
      visited[i] = 1;
      while (!bfs.empty()) {
        int curr = bfs.front();
        cout << curr << " ";
        bfs.pop();
        for (int s = 0; s < adj[curr].size(); ++s) {
          int node = adj[curr][s];
          if (visited[node] == 0) {
            if (isB) {
              wh.insert(adj[curr][s]);
            } else {
              bl.insert(adj[curr][s]);
            }
            bfs.push(node);
            visited[node] = 1;
          }
        }
        isB = !isB;

      }
      cout << endl;
      if (maxS < wh.size()) {
        ans = wh;
        maxS = wh.size();
      }
      else if (maxS < bl.size()) {
        ans = bl;
        maxS = bl.size();
      }
    }
    printf("%d\n",maxS);
    set<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); ++it) {
      printf("%d ",*it);
    }
  }
  return 0;
}
