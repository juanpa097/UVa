#include "bits/stdc++.h"
using namespace std;
class UnionFind { // OOP style
  private:
    vector<int> p, rank; // remember: vi is vector<int>
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for (int i = 0; i < N; i++)
        p[i] = i;
    }
    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if (!isSameSet(i, j)) { // if from different set
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x; // rank keeps the tree short
        else {
          p[x] = y;
          if (rank[x] == rank[y])
            rank[y]++;
        }
      }
    }
};

int main () {
  int k;
  scanf("%d",&k);
  while (k--) {
    int f;
    int cont = 0;
    scanf("%d",&f);
    set<string> names;
    map<string,int> dict;
    UnionFind diSet (f);
    for (int i = 0; i < f; i++) {
      string name1, name2;
      cin >> name1 >> name2;
      if (names.find(name1) != names.end()) {
        names.insert(name1);
        dict[name1] = cont;
        cont++;
      }
      if (names.find(name2) != names.end()) {
        names.insert(name2);
        dict[name2] = cont;
        cont++;
      }
      diSet.unionSet(dict[name1], dict[name2]);
    }
  }
}
