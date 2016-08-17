#include "bits/stdc++.h"
using namespace std;

string give (string & str) {
  string ret = "";
  for (int i = 0; i < str.size(); i++) {
    if ((str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97)){
      if (str[i] <= 90 && str[i] >= 65) {
        str[i]+= 32;
      }
      ret+=str[i];
    }
  }
  return ret;
}

vector <string> foo (string & str) {
  vector<string> vec;
  string temp = "";
  for (int i = 0; i < str.size(); i++) {
    if ((str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97)) {
      temp += str[i];

    } else {
      vec.push_back(temp);
      temp = "";
    }
  }
  vec.push_back(temp);
  return vec;
}

int main () {
  string in;
  set<string> dict;
  set<string>::iterator it;
  while (getline(cin,in)) {

    vector<string> vec = foo(in);

    for (int i = 0; i < vec.size(); i++) {
      string temp = vec[i];
      string newStr = give(vec[i]);
      dict.insert(newStr);
    }


    //string newStr = give(in);
    //dict.insert(newStr);
  }

  for (it = dict.begin(); it != dict.end(); ++it) {
    if (*it != "") {
      cout << *it << endl;
    }
  }
}
