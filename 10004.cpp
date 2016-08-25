#include "bits/stdc++.h"
/*
5
5
0 1
0 2
0 3
2 4
3 4
*/
using namespace std;
bool biCol (vector < vector <int> > & gra) {
  set<int> visited;
  queue<int> q;
  char c = 'a';
  map <int,char> color;
  q.push(0);
  color[0] = c;
  visited.insert(0);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    c = color[node];
    if (c == 'a') c = 'b';
    else c = 'a';
    for (int i = 0; i < gra[node].size(); i++) {
      int tempNode = gra[node][i];
      if (visited.find(tempNode) == visited.end()) {
        color[tempNode] = c;
        q.push(tempNode);
        visited.insert(tempNode);
      } else {
        if (color[tempNode] != c) return false;
      }
    }
  }
  return true;
}

int main () {
  int n = 0;
  while (scanf("%d",&n) != EOF) {
    if (n == 0) break;
    vector < vector <int> > gra(n);
    int l;
    scanf("%d",&l);
    while (l--) {
      int nodA, nodB;
      scanf("%d",&nodA);
      scanf("%d",&nodB);
      gra[nodA].push_back(nodB);
      gra[nodB].push_back(nodA);
    }
    if (biCol(gra)) {
      cout << "BICOLORABLE." << endl;
    } else {
      cout << "NOT BICOLORABLE." << endl;
    }
  }
}
