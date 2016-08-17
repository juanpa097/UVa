#include <iostream>
#include <vector>
#include <set>


using namespace std;

int main(int argc, char const *argv[]) {

  int n = 0;

  while (cin >> n) {
    set <int> cont;

    int a , b;

    for (int i = 0; i < n; i++) {
      int temp  = 0;
      cin >> temp;

      if (i == 0) {
        a = temp;
      } else {
        b = temp;
        int dif = a - b;
        if (dif < 0) dif *= -1;
        cont.insert(dif);
        a = b;
      }
    }


    bool flag = true;
    set<int>::iterator it;
    for (int i = 1; i <= n-1; i++) {
      it = cont.find(i);
      if (it == cont.end()) flag = false;
    }

    if (flag) {
      cout << "Jolly" << endl;
    } else {
      cout << "Not jolly" << endl;
    }

  }

  return 0;
}
