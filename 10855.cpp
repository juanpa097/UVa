#include "bits/stdc++.h"
using namespace std;

int findIn (vector<string> & big, vector<string> & small) {
  int N = big.size();
  int n = small.size();
  int cont = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i + n <= N && j + n <= N) {
        if (big[i][j] == small[0][0]) {
          int tempi = i, tempj = j;
          bool flag = true;
          for (int p = 0; p < n; ++p) {
            if (!flag) break;
            tempj = j;
            for (int q = 0; q < n; ++q) {
              if (big[tempi][tempj] != small[p][q]) {
                flag = false;
                break;
              }
              ++tempj;
            }
            ++tempi;
          }
          if (flag) ++cont;
        }
      }
    }
  }
  return cont;
}

vector<string> rotate (vector<string> big) {
  std::vector<string> v (big.size());
  int tempi = 0;
  for (int j = 0; j < big.size(); j++) {
    string toPush ="";
    for (int i = big.size() - 1; i >= 0; --i) {
      toPush+=big[i][j];
    }
    v[tempi] = toPush;
    ++tempi;
  }
  return v;
}

int main(int argc, char const *argv[]) {
  int N, n;
  while (scanf("%d%d",&N,&n) && (N || n)) {
    vector<string> big(N);
    vector<string> small(n);
    for (int i = 0; i < N; ++i) {
      string row;
      cin >> row;
      big[i] = row;
    }
    for (int i = 0; i < n; ++i) {
      string row;
      cin >> row;
      small[i] = row;
    }
    for (int i = 0; i < 4; ++i) {
      if (i == 3) cout << findIn(big,small);
      else cout << findIn(big,small) << " ";
      small = rotate(small);
    }
    cout << "\n";

  }
  return 0;
}
