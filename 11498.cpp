#include "bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;

int main () {
  int c = 0;
  while (scanf("%d",&c) != EOF) {
    if (c == 0) break;
    int oX, oY;
    scanf("%d", &oX);
    scanf("%d", &oY);
    while (c--) {
      int x, y;
      scanf("%d", &x);
      scanf("%d", &y);

      bool east = (x > oX);
      bool north = (y > oY);
      bool border = ((x == oX)||(y == oY));
      if (border) {
        printf("divisa\n");
      } else if (north && east) {
        printf("NE\n");
      } else if (north && !east) {
        printf("NO\n");
      } else if (!north && east) {
        printf("SE\n");
      } else if (!north && !east) {
        printf("SO\n");
      }
    }
  }
}
