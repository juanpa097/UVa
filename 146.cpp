#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  string str;

  while (cin >> str) {
    if (str == "#") break;
    if (std::next_permutation(str.begin(),str.end())) {
      for (int i = 0; i < str.size(); ++i){
        cout << str[i];
      }
      cout << endl;
    } else {
      printf("No Successor\n");
    }
  }
  return 0;
}
