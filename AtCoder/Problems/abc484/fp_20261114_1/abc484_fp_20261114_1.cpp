#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int op(int l, int r) {
  if (l == r) return l;
  if (l == -1) return r;
  if (r == -1) return l;
  return -2;
}

int e() { return -1; }

int main() {
  int n, q;
  cin >> n >> q;
  segtree<int, op, e> seg(n);
  rep(i, n) {
    int in;
    cin >> in;
    seg.set(i, in);
  }
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    b--;
    if (a == 1) {
      seg.set(b, c);
    } else {
      int r = seg.prod(b, c);
      if (r == -2)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  }
  return 0;
}