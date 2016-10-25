#include "bits/stdc++.h"
using namespace std;

int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[]) {
  int n, m;

  while (scanf("%d", &n) != EOF) {
    int books [n];
    for (int i = 0; i < n; ++i){
      int price;
      scanf("%d",&price);
      books[i] = price;
    }
    sort (books, books + n);
    scanf("%d",&m);

    cin.ignore();

    map <int, int> buy;
    for (int i = 0; i < (n); ++i) {
      int temp = m - books[i];
      int *found = (int*) bsearch (&temp, books, n, sizeof (int), compareints);
      if (found && found != (books + i)) {
        buy[books[i]] = temp;
      }
      else if (found == (books + i) && found == (books + i + 1)) {
        buy[books[i]] = temp;
      }
    }

    map<int,int>::iterator it = buy.begin();
    int dif = (1<<29);
    int a = 0, b = 0;
    for (it = buy.begin(); it != buy.end(); ++it) {
      if (abs (it->first - it -> second) < dif) {
        a = it->first;
        b = it->second;
        dif = abs (it->first - it -> second);
      }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);

  }
  return 0;
}
