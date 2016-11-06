#include "bits/stdc++.h"
using namespace std;
int maxLength(vector < int > a, int k) {
    //sort (a.begin(), a.end());
    if (a.size() == 0) return 0;
    int cont = 0;
    int sum = 0;
    int ma = -1;
    //a.insert(a.end(),a.begin(),a.end());
    int idx = 0;
    vector <int> ans;
    for (int i = 0; i < a.size(); ++i) {
      sum+=a[i];
      if (sum <= k) {
        ++cont;
      } else {
        //ans.push_back(cont);
        ma = max(ma, cont);

        cont = 1;
        i = ++idx;
        sum = a[idx];
      }
    }
    ma = max(ma, cont);
    //ans.push_back(cont);
    //sort(ans.begin(), ans.end());
    //cont = ans[ans.size() - 1];
    return ma;
}

int main() {
    int TC;
    cin >> TC;
    //cout << "TC: " << TC << endl;
    vector <int > v;
    for (int i = 0; i < TC; ++i) {
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    int k;
    cin >> k;
    cout << maxLength(v,k) << endl;
    return 0;
}
