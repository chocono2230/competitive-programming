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
using mint = modint998244353;

using S = tuple<mint, mint, bool>;
S op(S l, S r) {
  auto [l0, l1, l2] = l;
  auto [r0, r1, r2] = r;
  if (l2) return r;
  if (r2) return l;

  mint x0 = l0 * l1 + r0 * r1;
  mint x1 = 1;
  return {x0, x1, false};
}
S e() { return S(0, 1, true); }

int main() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<mint> af(n + 1), bf(n + 1);
  segtree<S, op, e> sgt(n + 1);
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  rep(i, n) {
    af.add(i, a.at(i));
    bf.add(i, b.at(i));
    af.add(i + 1, -a.at(i));
    bf.add(i + 1, -b.at(i));
  }
  auto add = [&](int pos, S s) {
    auto [r0, r1, r2] = sgt.get(pos);
    if (r2) {
      sgt.set(pos, s);
      return;
    }
    auto [s0, s1, s2] = s;
    r0 += s0;
    r1 += s1;
    sgt.set(pos, S(r0, r1, r2));
  };
  rep(i, n) {
    S s(a.at(i), b.at(i), false);
    add(i, s);
    S t(-a.at(i), -b.at(i), false);
    add(i + 1, t);
  }
  rep(i, n) {
    auto [p0, p1, p2] = sgt.prod(0, i + 1);
    cerr << i << " " << p0.val() << " " << p1.val() << " " << p2 << endl;
    auto [q0, q1, q2] = sgt.prod(0, i + 2);
    cerr << i << " " << q0.val() << " " << q1.val() << " " << q2 << endl;
    p0 -= q0;
    cout << i << " " << p0.val() << endl;
  }
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      S s(x, 0, false);
      add(l, s);
      S t(-x, 0, false);
      add(r, t);
    }
    if (mode == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      S s(0, x, false);
      add(l, s);
      S t(0, -x, false);
      add(r, t);
    }
    if (mode == 3) {
      int l, r;
      cin >> l >> r;
      l--;
      auto [p0, p1, p2] = sgt.prod(0, l + 1);
      auto [q0, q1, q2] = sgt.prod(0, r);
      p0 -= q0;
      cout << p0.val() << endl;
    }
  }
  return 0;
}