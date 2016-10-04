#include "bits/stdc++.h"
#define DEBUG cout <<
using namespace std;

struct point {
  double x ,y;
  point() {x = y = 0.0;}
  point (double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
  double x, y;
  vec (double _x, double _y) : x(_x), y(_y) {}
};

double hypot (double dx, double dy) {
  return sqrt(dx* dx + dy*dy);
}

double dist (point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

vec scale (vec v, double s) {
  return vec(v.x * s, v.y * s);
}

point translate (point p, vec v) {
  return point(p.x + v.x, p.y + v.y);
}

vec toVec(point a, point b) {
  return vec(b.x - a.x, b.y - a.y);
}

double dot (vec a, vec b) {
  return (a.x * b.x + a.y * b.y);
}

double norm_sq (vec v) {
  return v.x * v.x + v.y * v.y;
}

double distToLine (point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap,ab) / norm_sq(ab);
  c = translate (a, scale(ab,u));
  return dist(p, c);
}

double distToLineSegment (point p, point a, point b, point &c) {
  vec ap = toVec(a, p), ab = toVec(a,b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (u > 1.0) {
    c = point(b.x, b.y);
    return dist(p, b);
  }
  return distToLine (p, a, b, c);
}

int main(int argc, char const *argv[]) {
  double n;
  while (true) {
    cin >> n;
    double xr, yr;
    double minRadio = numeric_limits<double>::max();
    if (cin.fail()) {
      break;
    }
    double primx, primy;
    cin >> xr >> yr;
    point fabr (xr,yr);
    double xi, yi, xprev, yprev;
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        cin >> xprev >> yprev;
        primx = xprev;
        primy = yprev;
      } else {
        cin >> xi >> yi;
        point tempA = point (xi, yi);
        point tempB = point(xprev, yprev);
        point closestPoint = point();
        double rad = distToLineSegment (fabr, tempB, tempA, closestPoint);
        minRadio = min(minRadio, rad);
        xprev = xi;
        yprev = yi;
      }
    }
    point tempA = point (xi, yi);
    point tempB = point(primx, primy);
    point closestPoint = point();
    double rad = distToLineSegment (fabr, tempA, tempB, closestPoint);
    minRadio = min(minRadio, rad);


    double roundNum = minRadio * 1000;
    roundNum += 0.5555;
    int trunk = int (roundNum);
    double res = double (trunk) / 1000;
    cout << res << endl;


    printf("%.3f\n",minRadio);
  }
  return 0;
}
