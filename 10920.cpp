#include "bits/stdc++.h"
using namespace std;
int main(int argc, char const *argv[]) {
  /*
3 1
3 3
3 9
5 9
5 10
0 0

Line = 2, column = 2.
Line = 3, column = 1.
Line = 3, column = 3.
Line = 4, column = 4.
Line = 5, column = 4.
  */
  long long n, m;
  while ((cin >> n >> m) && (n || m)) {
    long long mid = n/2;
    long long ring = round(sqrt(m));
    long long i = mid;
    long long j = mid;
    long long adI = -1;
    long long adJ = -1;
    long long discount = (((ring - 1)*(ring-1)) + (ring -1));
    if (ring % 2 == 0) {
      i = j = (n/2) - (ring/2);
      adI = adJ = (ring);
    } else {
      i = j = (n/2) + (ring/2);
      adI = adJ = (ring * -1);
    }

    m -= discount;

    long long printi , printj;

    --m;
    printi = n - i;
    printj = j + 1;
    bool flag = false;
    if (!m || m < 0) {
      flag = true;
      cout << "Line = " << printi << ", column = " << printj<<"."<< endl;
    }
    for (long long k = 0; k < n - 1 && !flag; ++k) {
      long long p = i;
      while (i != p+adI && !flag) {
        if (adI < 0) --i;
        else ++i;
        --m;
        printi = n - i;
        printj = j + 1;
        if (!m) {
          flag = true;
          cout << "Line = " << printi << ", column = " << printj<<"."<< endl;
          break;
        }
      }
      p = j;
      while (j != p+adJ && !flag) {
        if (adJ < 0) --j;
        else ++j;
        --m;
        printi = n - i;
        printj = j + 1;
        if (!m) {
          flag = true;
          cout << "Line = " << printi << ", column = " << printj<<"."<< endl;
          break;
        }
      }
      long long newVal = abs(adI) + 1;
      if (adI < 0) adI =adJ= newVal;
      else adI =adJ= newVal * -1;
    }
    long long p = i;
    while (i != p+adI && !flag+ 1) {
      if (adI < 0) --i;
      else ++i;
      --m;
      printi = n - i;
      printj = j + 1;
      if (!m) {
        flag = true;
        cout << "Line = " << printi << ", column = " << printj<<"."<< endl;
        break;
      }
    }
  }
	return 0;
}
