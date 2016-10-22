#include "bits/stdc++.h"
using namespace std;

int ans;
vector<int> ansv;


void printVec (vector<int> & v) {
  for (int i = 0; i < v.size(); ++i){
    if (i != v.size() -1)
      printf("%d ",v[i]);
    else
      printf("%d",v[i]);

  }
  printf("\n");
}

bool adjToBlack (bitset<110> & color, vector <vector <int> > &adj, int node) {
  for (int i = 0; i < adj[node].size(); ++i) {
    if (color[adj[node][i]] == 1) {
      return true;
    }
  }
  return false;
}

void numBlack (vector <vector <int> > &adj, int node, int n, bitset<110> & color) {
  if (node == n + 1) {
    int cont = 0;
    std::vector<int> v;
    for (int i = 0; i <= 100; ++i) {
      if (color[i]) {
         ++cont;
         v.push_back(i);
         //cout << i << " ";
       }
    }
    if (cont > ans) {
      ans = cont;
      ansv = v;
    }
    return;
  }
  vector<int> black;
  if (!adjToBlack(color, adj, node)) {
    color[node] = 1;
    numBlack(adj, node + 1, n, color);
  }
  color[node] = 0;
  numBlack(adj, node + 1, n, color);
}



int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  while (TC--) {
    int n, m;
    scanf("%d%d",&n,&m);
    vector< vector <int> > adj(n + 1);
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d",&a,&b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    cin.ignore();
    ans = -1;
    bitset<110> color;
    numBlack(adj, 1, n, color);
    printf("%d\n", ans);
    printVec(ansv);

  }
  return 0;
}
