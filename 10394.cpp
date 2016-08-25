#include "bits/stdc++.h"

using namespace std;
#define MAX 20000100

void makeCriba (vector<bool> &v) {
  v[0] = v[1] = false;
  for (long long i = 2; i < sqrt(v.size()); ++i) {
    if (v[i]) {
      for (long long j = 2; j*i < v.size(); ++j) {
        v[i*j] = false;
      }
    }
  }
}

void arrPrimos (vector <bool> & crib, vector<int> & v) {
  for (long long i = 0; i < crib.size(); i++) {
    if (crib[i]) v.push_back(i);
  }
}

int main () {
  vector<bool> criba (MAX, true);
  vector<int> primos;
  vector < pair <int, int> > hermanos;
  makeCriba(criba);
  arrPrimos(criba, primos);
  for (long long i = 0; i < primos.size() - 1; i++) {
    if (primos[i+1] - primos[i] == 2) {
      hermanos.push_back(make_pair(primos[i], primos[i+1]));
    }
  }

  int n;
  while (cin >> n) {
    --n;
    printf("(%d, %d)\n",hermanos[n].first, hermanos[n].second);
  }

}
