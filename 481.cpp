#include "bits/stdc++.h"
using namespace std;
typedef vector<int> vi;
vi A;

int ceilIndex(int T[], int end, int s) {
  int start = 0;
  int middle;
  int len = end;
  while(start <= end) {
    middle = (start + end) / 2;
    if(middle < len && A[T[middle]] < s && s <= A[T[middle + 1]])
      return middle + 1;
    else if (A[T[middle]] < s)
      start = middle + 1;
    else
      end = middle - 1;
  }
  return -1;
}

vi LIC() {
  int len = 0;
  int T[A.size()];
  int R[A.size()];
  memset (R, -1, sizeof R);
  T[0] = 0;
  for (int i = 1; i < A.size(); ++i) {
    if(A[T[0]] > A[i]) {
      T[0] = i;
    } else if (A[T[len]] < A[i]) {
      len++;
      T[len] = i;
      R[T[len]] = T[len-1];
    } else {
      int index = ceilIndex(T,len,A[i]);
      T[index] = i;
      R[T[index]] = T[index-1];
    }
  }

  int index = T[len];
  vi ans(len + 1);
  int i = 0;
  //ans[0] = A[T[0]];
  while (index != -1) {
    ans[i++] = A[index];
    index = R[index];
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  int t;

  while(scanf("%d",&t) != EOF) {
    A.push_back(t);
  }
  vi ans = LIC();
  int size = ans.size();

  printf("%d\n-\n",size);
  for (int i = ans.size() - 1 ; i >= 0; --i) {
    printf("%d\n",ans[i]);
  }
  return 0;
}
