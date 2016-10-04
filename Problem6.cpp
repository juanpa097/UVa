
#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  /*map <int,int> lav;
  lav[1] = 1;
  lav[5] = 4;
  lav[7] = 6;
  lav[11] = 9;
  lav[19] = 18;
  map<int,int> lavado[5];
  lavado[0] = 1;
  lavado[1] = 5;
  lavado[2] = 7;
  lavado[3] = 11;
  lavado[4] = 18;*/

  double pi = 3.14159265359;
  double res = pi * 3;
  res = res/ 2.0000;
  res *= 1000.000;
  res+= 0.5;
  int a = res;
  double ans = double(a) / 1000.00;
  cout << ans << endl;

  return 0;
}
