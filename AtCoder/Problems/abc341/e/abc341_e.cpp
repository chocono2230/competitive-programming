#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define repit(itr, x) for (auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr, x) for (auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int op(int l, int r) { return max(l, r); }
int e() { return 0; }

int main() {
  int n, q;
  cin >> n >> q;
  segtree<int, op, e> mxt(n - 1);
  string s;
  cin >> s;
  rep(i, s.size() - 1) {
    if (s.at(i) != s.at(i + 1)) {
      mxt.set(i, 0);
    } else {
      mxt.set(i, 1);
    }
  }
  while (q--) {
    int mode, l, r;
    cin >> mode >> l >> r;
    l--;
    r--;
    if (mode == 1) {
      auto fc = [&](int l) {
        int p = mxt.get(l);
        int add = (p == 0 ? 1 : 0);
        mxt.set(l, add);
      };
      if (l != 0) {
        fc(l - 1);
      }
      if (r != n - 1) {
        fc(r);
      }
    } else {
      int mx = mxt.prod(l, r);
      if (mx == 0)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}