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

mint op(mint l, mint r) {
  if (l == 0) return r;
  return l;
}
mint e() { return 0; }

using F = pair<mint, mint>;

mint mapping(F f, mint m) { return f.first + f.second * m; }
F composition(F f, F g) {
  return {f.first + f.second * g.first, f.second * g.second};
}
F id() { return {0, 1}; }

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  lazy_segtree<mint, op, e, F, mapping, composition, id> lsg(n);
  rep(i, n) lsg.set(i, a.at(i));
  while (m--) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    F f(0, 0);
    mint y = x;
    f.first = y / (r - l);
    f.second = (mint)(r - l - 1) / (r - l);
    lsg.apply(l, r, f);
  }
  rep(i, n) {
    if (i != 0) cout << " ";
    cout << lsg.get(i).val();
  }
  cout << endl;
  return 0;
}