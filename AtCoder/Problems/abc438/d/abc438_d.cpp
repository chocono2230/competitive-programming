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

using S = long long;
using F = long long;

const S INF = 8e18;

S op(S a, S b) { return std::max(a, b); }
S e() { return -INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> b(n);
  rep(i, n) cin >> b.at(i);
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);
  auto fc = [](vector<int> a) {
    vector<ll> sums(a.size() + 1, 0);
    rep(i, a.size()) sums.at(i + 1) = sums.at(i) + a.at(i);
    return sums;
  };
  auto as = fc(a);
  auto bs = fc(b);
  auto cs = fc(c);
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(as);
  ll ans = 0;
  // rep(i, as.size()) cerr << lsg.get(i) << " ";
  // cerr << endl;
  rep2(y, 1, n - 1) {
    lsg.apply(1, y + 1, b.at(y));
    // rep(i, as.size()) cerr << lsg.get(i) << " ";
    // cerr << endl;
    ll add = cs.back() - cs.at(y + 1);
    add += lsg.prod(1, y + 1);
    ans = max(ans, add);
  }
  cout << ans << endl;
  return 0;
}