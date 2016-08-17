#include "bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;

int main () {
  map<int,int> a;
  queue <int> b;
  int n = 0;
  while (cin >> n) {
    if (a[n] == 0) {
      b.push(n);
    }

    ++a[n];
  }
  while (!b.empty()) {
    int c = b.front();
    cout << c << " " << a[c] << endl;
    b.pop();
  }
}
