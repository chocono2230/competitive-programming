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

using S = pair<ll, int>;
S op(S l, S r) {
  if (l.first > r.first) return l;
  return r;
}
S e() { return {-2 * INF, -1}; }

int main() {
  int n;
  ll c;
  cin >> n >> c;
  segtree<S, op, e> lmx(n), rmx(n);
  vector<ll> dp(n, -INF);
  dp.at(0) = 0;
  auto set = [&](int i, ll nw) {
    lmx.set(i, {-c * i + nw, i});
    rmx.set(i, {-c * (n - i - 1) + nw, i});
  };
  rep(i, n) set(i, dp.at(i));
  int q;
  cin >> q;

  vector<ll> dbgdp(n, -INF);
  dbgdp.at(0) = 0;
  while (q--) {
    int t;
    ll p;
    cin >> t >> p;
    t--;
    auto lx = rmx.prod(0, max(1, t));
    auto rx = lmx.prod(t, n);
    int li = lx.second, ri = rx.second;
    ll add = -c * abs(t - li) + p + dp.at(li);
    ll add2 = -c * abs(t - ri) + p + dp.at(ri);
    dp.at(t) = max({dp.at(t), add, add2});
    set(t, dp.at(t));
    // rep(i, n) cerr << (dp.at(i) == -INF ? -1 : dp.at(i)) << " ";
    // cerr << endl;

    // auto dbgmx = dbgdp.at(t);
    // rep(i, n) {
    //   ll nx = -c * abs(i - t) + dbgdp.at(i) + p;
    //   dbgmx = max(dbgmx, nx);
    // }
    // dbgdp.at(t) = dbgmx;
    // rep(i, n) cerr << (dbgdp.at(i) == -INF ? -1 : dbgdp.at(i)) << " ";
    // cerr << endl;
    // cerr << "----------------" << endl;
  }
  ll ans = *max_element(ALL(dp));
  cout << ans << endl;
  return 0;
}