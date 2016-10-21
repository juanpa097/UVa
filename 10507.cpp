#include "bits/stdc++.h"
using namespace std;

class UnionFind { // OOP style
  private:
    vector< vector <int> > adj;
  public:
    UnionFind(int N) {
      vector< vector <int> > adj1 (N, vector<int> (N,0));
      adj = adj1;
    }
    bool isSameSet(int i, int j) {
      return (adj[i][j] == 1);
    }
    void unionSet(int i, int j) {
      if (!isSameSet(i, j)) { // if from different set
        adj[i][j] = 1;
        adj[j][i] = 1;
      }
    }
    void printM() {
      for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj.size(); ++j) {
          cout << adj[i][j] << " ";
        }
        cout << endl;
      }
    }
};

bool isStart (char c, string b) {
  for (int i = 0; i < b.size(); ++i){
    if (b[i] == c) return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  int n;
  while (scanf("%d",&n) != EOF) {
    UnionFind uf (26);
    int con;
    scanf("%d", &con);
    string wake;
    cin >> wake;
    for (int i = 0; i < con; ++i) {
      string par;
      cin >> par;
      uf.unionSet(par[0] - 'A', par[1] - 'A');
      //uf.printM();
    }

    int years = 0;
    for (int p = 0; p < 26; ++p) {
      bool in = false;
      string toAdd = "";
      for (int i = 0; i < 26; ++i) {
        int cont = 0;
        for (int j = 0; j < wake.size(); ++j) {
          int root = wake[j] - 'A';
          char x = i + 'A', y = root + 'A';
          if (!isStart(x, wake) && uf.isSameSet(i, root)){
            //cout << x << " " << y << endl;
            ++cont;
          }
        }
        if (cont >= 3) {
          char app = 'A' + i;
          toAdd += app;
          // = n;
          //cout << "Actual Wake: " << wake << endl;
          //cout << "P: " << p << " Add: " << app << endl;
          in = true;
        }
      }
      if (in) ++years;
      wake += toAdd;
    }
    int ans = wake.size();
    //cout << "Ans: " << ans << "N: " << n << endl;

    if (n == 3)
      printf("WAKE UP IN, %d, YEARS\n", 0);
    else {
      if (years == 0 || ans < n)
        printf("THIS BRAIN NEVER WAKES UP\n");
      else
        printf("WAKE UP IN, %d, YEARS\n", years);
      }

    cin.ignore();

  }
	return 0;
}
