#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {

  int n  = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string parra = "";
    int k;

    cin >> k;

    map <char, int> vals;
    for (int i = 0; i < k; i++) {
      char key;
      int pay;
      cin >> key >> pay;
      vals[key] = pay;
    }

    int m = 0;
    cin >> m;
    double cont = 0;
    cin.ignore();
    for (int i = 0; i < m; i++) {
      getline (cin,parra);
      for (int j = 0; j < parra.size(); j++) {
        cont += vals[parra[j]];
      }
    }

    cout << setprecision(2) << fixed << (cont / 100.0) << '$' << endl;

  }


  return 0;
}
