#include "bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;

int main () {

  int h, u, d, f;
  while (scanf("%d %d %d %d",&h,&u,&d,&f) != EOF) {
    if (h == 0) break;

    double distance = 0.0;
    int day = 1;

    double climb = double (u);

    while ((distance <= h)&&(distance >=0)) {
      distance += climb;
      if ((distance > h)||(distance < 0)) break;
      distance = distance - double (d);
      if ((distance > h)||(distance < 0)) break;
      ++day;

      climb -= ((double(f)/100.0) * double(u));
      //cout << "Distance Climb: " << climb << endl;

      if (climb < 0) climb = 0;
    }

    if (distance < 0) {
      printf("failure on day %d\n", day);
    } else {
      printf("success on day %d\n", day);
    }
  }
}
