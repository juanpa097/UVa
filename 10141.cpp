#include "bits/stdc++.h"
//#include <bits/stdc++.h>

// NOT DONE

using namespace std;

int main () {
  int n, p;
  int k = 1;
  while (scanf("%d %d", &n,&p) != EOF) {
    if (n == 0 && p == 0) break;
    string nameAns;
    double priceAns;
    double complience = -1.0;
    double number_of_requirements = double (n);
    set<string> req;
    cin.ignore();
    while (n--) {
      string str;
      getline(cin,str);
      req.insert(str);
    }
    //cin.ignore();
    while (p--) {
      int reqMet = 0;
      string name;
      double price;
      int numReq;
      getline(cin,name);
      cin >> price >> numReq;
      //scanf("%lf %d",&price, &numReq);
      cin.ignore();
      while (numReq--) {
        string newReq;
        cin.ignore();
        getline(cin,newReq);
        set<string>::iterator it;
        it = req.find(newReq);
        if (it != req.end()) {
          ++reqMet;
        }
      }
      double thisComp = reqMet / number_of_requirements;
      if (thisComp > complience) {
        complience = thisComp;
        priceAns = price;
        nameAns = name;
      }
      if (thisComp == complience) {
        if (price < priceAns) {
          complience = thisComp;
          priceAns = price;
          nameAns = name;
        }
      }
    }

    printf("RFP #%d\n",k);
    cout << nameAns << endl;
    k++;
  }
}
