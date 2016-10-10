#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  unsigned long long int n;
  while (cin >> n && (n != 0)) {
    vector<int> v;
    for (int i = 0; i < 32; ++i) {
      unsigned long long int j = 1 << i;
      if ((n & j) == j) {
        v.push_back(i);
      }
    }

    unsigned long long int a = 0;
    unsigned long long int b = 0;
    for (int i = 0; i < v.size(); i+= 2) {
      int idx = v[i];
      unsigned long long int j = 1 << idx;
      unsigned long long int p = (a|j);
      a = p;
    }

    for (int i = 1; i < v.size(); i+= 2) {
      int idx = v[i];
      unsigned long long int j = 1 << idx;
      b = (b|j);
    }

    cout << a << " " << b << endl;

  }
  return 0;
}
