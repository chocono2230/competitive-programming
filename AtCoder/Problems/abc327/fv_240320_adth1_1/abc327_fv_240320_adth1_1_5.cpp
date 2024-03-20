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
  const int sz = 200005;
  lazy_segtree<S, op, e, F, mapping, composition, id> lsg(sz);
  vector<pair<int, int>> events;
  rep(i, n) {
    int t, x;
    cin >> t >> x;
    events.push_back({t, x});
    events.push_back({t + d, -x});
  }
  sort(ALL(events));
  int ans = 0;
  for (auto [t, x] : events) {
    int add = 1;
    if (x < 0) {
      x *= -1;
      add = -1;
    }
    int l = x, r = min(x + w, sz);
    lsg.apply(l, r, add);
    int mx = lsg.all_prod();
    // cerr << mx << endl;
    ans = max(ans, mx);
  }
  cout << ans << endl;
  return 0;
}