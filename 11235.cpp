#include "bits/stdc++.h"
using namespace std;

class SegmentTree {
  private:
    vector<int> st, A;
    int n;
    int left(int p) {return p << 1;}
    int right(int p) {return (p << 1) + 1;}

    void build(int p, int L, int R) {
      if (L == R)
        st[p] = L;
      else {
        build(left(p), L, (L + R) / 2);
        build(right(p), (L + R)/2 + 1, R);
        int p1 = st[left(p)], p2 = st[right(p)];
        st[p] = (A[p1] >= A[p2]) ? p1 : p2;
      }
    }
    int rmq (int p, int L, int R, int i, int j) {
      if (i > R || j < L) return -1;
      if (L >= i && R <= j) return st[p];

      int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
      int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
      if (p1 == -1) return p2;
      if (p2 == -1) return p1;
      return (A[p1] >= A[p2]) ? p1 : p2;
    }
  public:
    SegmentTree(const std::vector<int> & _A) {
      A = _A;
      n = (int)A.size();
      st.assign(4 * n, 0);
      build(1, 0, n-1);
    }
    int rmq (int i, int j) {
      return rmq(1,0,n-1,i,j);
    }
};

int case1 (vector<int> &v, vector<int> &cont, vector<int> &start, int i, int j) {
  return (j - i) + 1;
}
int case2 (vector<int> &v, vector<int> &cont, vector<int> &start, int i, int j) {
  SegmentTree st (cont);
  int k = start[i] + cont[i] - 1;
  int frecI = (k - i) + 1;
  int frecJ = (j - start[j]) + 1;
  int p1 = k + 1;
  int p2 = start[j] - 1;
  int frecK = st.rmq (p1,p2);
  //printf("Frec I: %d\n",frecI);
  //printf("Frec J: %d\n",frecJ);
  //printf("Frec K: %d\n",frecK);
  return max (frecI, max(frecJ,cont[frecK]));
}



int main(int argc, char const *argv[]) {
  int n, q;

  while (scanf("%d",&n ) && n) {
    scanf("%d",&q);
    std::vector<int> v(n);
    std::vector<int> start(n);
    std::vector<int> cont(n);
    int rep[200010] = {0};
    int begin = 0;
    for (int i = 0; i < n; ++i) {
      int t;
      scanf("%d",&t);
      v[i] = t;
      if (i - 1 >= 0 && v[i] != v[i-1])
        begin = i;
      start[i] = begin;
      rep[t+100000]+= 1;
    }
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      sum = rep[v[i]+100000];
      cont[i] = sum;
    }

    for (int i = 0; i < q; ++i) {
      int l, r;
      scanf("%d %d",&l,&r);
      --l;
      --r;
      int ans = 0;
      //cout << "L: " << l << " R: " << r << endl;
      if (v[l] == v[r]) {
        ans = (r - l) + 1;
      }else {
        ans = case2(v,cont,start,l,r);
      }
      cout << ans << endl;
    }
    v.clear();
    cont.clear();
    start.clear();
  }
  return 0;

}
