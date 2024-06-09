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

using S = tuple<mint, mint, mint, int>;
S op(S l, S r) {
  auto [a1, b1, s1, l1] = l;
  auto [a2, b2, s2, l2] = r;
  return {a1 + a2, b1 + b2, s1 + s2, l1 + l2};
}
S e() { return {0, 0, 0, 0}; }

using F = pair<mint, mint>;
S mapping(F f, S x) {
  auto [a1, b1, s1, l1] = x;
  auto [a2, b2] = f;
  S res = {a1 + a2 * l1, b1 + b2 * l1, 0, l1};
  mint s3 = s1;
  s3 += a2 * b1;
  s3 += b2 * a1;
  s3 += a2 * b2 * l1;
  get<2>(res) = s3;
  return res;
}
F composition(F f, F g) { return {f.first + g.first, f.second + g.second}; }
F id() { return {0, 0}; }

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(n);
  rep(i, n) { lsg.set(i, S(a.at(i), b.at(i), (mint)a.at(i) * b.at(i), 1)); }
  while (q--) {
    int mode;
    cin >> mode;
    if (mode == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      lsg.apply(l, r, {x, 0});
    }
    if (mode == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      lsg.apply(l, r, {0, x});
    }
    if (mode == 3) {
      int l, r;
      cin >> l >> r;
      l--;
      auto p = lsg.prod(l, r);
      cout << get<2>(p).val() << endl;
    }
  }
  return 0;
}