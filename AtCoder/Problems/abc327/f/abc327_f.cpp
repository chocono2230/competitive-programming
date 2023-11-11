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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return 0; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n, d, w;
  cin >> n >> d >> w;
  int sz = 200005;
  lazy_segtree<S, op, e, F, mapping, composition, id> lst(sz);
  vector<pair<int, int>> tx(n);
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    tx.at(i) = {t, x};
  }
  sort(ALL(tx));
  int lidx = 0;
  ll ans = 0;
  for (auto [t, x] : tx) {
    lst.apply(x, min(x + w, sz), 1);
    while (tx.at(lidx).first <= t - d) {
      auto [t1, x1] = tx.at(lidx++);
      lst.apply(x1, min(x1 + w, sz), -1);
    }
    ans = max(ans, lst.all_prod());
    // rep(i, 10) { cerr << lst.prod(i, i + 1) << " "; }
    // cerr << endl;
  }
  cout << ans << endl;
  return 0;
}