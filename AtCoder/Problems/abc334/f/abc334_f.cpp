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

using S = double;
using F = double;

const S INF = 8e18;

S op(S a, S b) { return std::min(a, b); }
S e() { return INF; }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<double, double>> xy(n + 1);
  cin >> xy.at(n).first >> xy.at(n).second;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    xy.at(i) = {x, y};
  }
  auto fc = [&](int i, int j) {
    auto [x, y] = xy.at(i);
    auto [x1, y1] = xy.at(j);
    return hypot(x1 - x, y1 - y);
  };

  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(n + k - 1);
  lsg.set(k - 1, fc(0, n));
  rep2(i, 1, n) {
    double ss = lsg.prod(i - 1, i - 1 + k);
    ss += fc(i - 1, n) + fc(n, i);
    lsg.apply(i, i + k - 1, fc(i - 1, i));
    lsg.set(i + k - 1, ss);
  }
  double ans = lsg.prod(n + k - 1 - k, n + k - 1);
  ans += fc(n - 1, n);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}