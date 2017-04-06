#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;



int LCS(vi &a, vi &b) {
  int N = a.size();
  int M = b.size();
  vector < vi > c (N + 1, vi(M + 1, 0));
  for (int i = 1; i < N + 1; ++i) {
    for (int j = 1; j < M + 1; ++j) {
      if (a[i - 1] == b[j - 1]) c[i][j] = max(c[i - 1][j - 1] + 1 ,max(c[i-1][j],c[i][j-1]));
      else c[i][j] = max(c[i-1][j],c[i][j-1]);
    }
  }
  // for(int i = 0; i < c.size(); ++i) {
  //   for(int j = 0; j < c.size(); ++j) {
  //     cout << c[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return c[N][M];
}

int main(int argc, char const *argv[]) {

  string line;
  int N = - 1;
  vi a;
  while(getline(cin, line)) {
    vi p;
    stringstream ss (line);
    int t;
    while (ss >> t) {
      p.push_back(t);
    }
    if(p.size() == 1) {
      N = p[0];
      getline(cin, line);
      stringstream ss1 (line);
      a.clear();
      while (ss1 >> t)
        a.push_back(t);
    } else {
      cout << "Size: " << a.size() << " N: " << N << endl;
      for (int i = 0; i < N; ++i) {
        cout << p[i] << "-";
      }
      cout << endl;
      for (int i = 0; i < N; ++i) {
        cout << a[i] << "-";
      }
      cout << endl << LCS(p,a) << endl;
      cout << endl << endl;
      //printf("%d\n",LCS(p,a));
    }

  }


  return 0;
}
