#include "bits/stdc++.h"
using namespace std;

/*
3
1 2 1 2 1
2 3 4 1 2 5 10 50 3 50
3 5 2 7 1 7 5 2 8 9 1 25 15 8 3 1 38 45 8 1
*/

vector<int> A;
bool can = false;


void back(int der, int iz, int at) {
  if (at == A.size()){
    if(iz == der) {
      can = true;
    } else {
      return;
    }
  } else {
    back(der + A[at],iz,at + 1);
    back(der,iz+ A[at], at + 1);
  }
}

int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  cin.ignore();
  while(TC--) {
    string line;
    getline(cin,line);
    stringstream ss(line);
    A.clear();
    int n;
    while(ss >> n) A.push_back(n);
    can = false;
    back(0,0,0);
    if(can) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
