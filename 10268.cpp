#include "bits/stdc++.h"
using namespace std;

long long p (long a, long to) {
  long long res = 1;
  for (int i = 0; i < to; ++i) {
    res*= a;
  }
  return res;
}

long long horner(vector<long long> poly, long long n, long long x)
{
    long long result = poly[0];  // Initialize result

    // Evaluate value of polynomial using Horner's method
    for (long long i=1; i<n; i++)
        result = result*x + poly[i];

    return result;
}

int main(int argc, char const *argv[]) {

  long long x;

  while (scanf("%lld",&x) != EOF) {
    stack<long long> s;
    string str;
    cin.ignore();
    getline(cin, str);
    stringstream ss (str);
    long long a;
    vector <long long> poly;
    while (ss >> a) {
      poly.push_back(a);
    }
    int k = poly.size() - 1;
    for (int i = 0; i < poly.size(); ++i) {
      poly[i] *= k--;
    }
    long long cont = horner(poly, poly.size()-1, x);

      printf("%lld\n", cont);

    //} else {
      //printf("0\n");
    //}

  }
  return 0;
}
