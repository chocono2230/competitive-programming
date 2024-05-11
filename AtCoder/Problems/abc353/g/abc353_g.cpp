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

const ll INF = 4e18;
ll C = 0;
ll T = 0;
using S = pair<ll, int>;

S op(S l, S r) {
  ll lc = abs(l.second - T) * C + l.first;
  ll rc = abs(r.second - T) * C + r.first;
  if (lc > rc) return l;
  return r;
}

S e() { return {-2 * INF, -1}; }

int main() {
  ll n, c;
  cin >> n >> c;
  C = c;
  segtree<S, op, e> seg(n);
  rep(i, n) { seg.set(i, S(-INF, i)); }
  seg.set(0, S(0, 0));
  int m;
  cin >> m;
  while (m--) {
    ll t, p;
    cin >> t >> p;
    t--;
    T = t;
    auto mx = seg.all_prod();
    int nxi = mx.second;
    auto add = seg.get(nxi);
    cerr << nxi << " " << add.first << endl;
    add.first += p - abs(nxi - t) * c;
    if (seg.get(t).first < add.first) {
      seg.set(t, add);
    }
    rep(i, n) cerr << seg.get(i).first << " ";
    cerr << endl;
  }
  ll ans = 0;
  rep(i, n) {
    auto p = seg.get(i);
    ans = max(ans, p.first);
  }
  cout << ans << endl;
  return 0;
}