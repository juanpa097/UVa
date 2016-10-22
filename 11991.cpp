#include "bits/stdc++.h"

#define TOP 1000010

using namespace std;


int main(int argc, char const *argv[]) {
  int n, m;

  while (scanf("%d%d", &n,&m) != EOF) {


    map <int,int> corr;
    vector <int> vec (n);
    int ma = -1;
    for (int i = 0; i < n; ++i) {
      int temp;
      scanf("%d", &temp);
      vec[i] = temp;
      ma = max(temp, ma);
    }

    map <int, vector<int> > v;
    //for (int i = 0; i < n; ++i) {
      //v[0][i] = vec[i];
    //}

    for (int i = 0; i < n; ++i) {
      int k = vec[i];
      v[k].push_back(i+1);

    }
    for (int i = 0; i < m; ++i) {
      int k, r;
      scanf("%d%d", &k,&r);
      int ans = 0;
      //cout << "Size: " << v[r].size() << endl;
      if (v[r].size() >= k) {
        ans = v[r][k-1];
        //cout << "ANS: " << v[r][k-1] << endl;
      }
      printf("%d\n",ans);

    }

  }
  return 0;
}
