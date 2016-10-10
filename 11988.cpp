#include "bits/stdc++.h"

using namespace std;

int main(int argc, char const *argv[]) {
  string str;
  while (cin >> str) {
    list<char> l;
    list<char>::iterator it = l.begin();
    for (int i = 0; i < str.size(); ++i) {
      if(str[i] == '[') {
        it = l.begin();
      }
      else if(str[i] == ']') {
        it = l.end();
      }
      else {
        l.insert(it,str[i]);
      }
    }
    for (it = l.begin(); it != l.end(); ++it) {
      cout << *it;
    }
    cout << "\n";
  }
  return 0;
}
