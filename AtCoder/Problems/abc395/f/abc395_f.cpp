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

int main() {
  int n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> ud(n);
  ll mn = 1e18;
  rep(i, n) {
    ll u, d;
    cin >> u >> d;
    ud.at(i) = {u, d};
    mn = min(mn, u + d);
  }
  auto fc = [&](ll mid) -> pair<bool, ll> {
    vector<ll> t(n, 0);
    rep(i, n) {
      auto [u, d] = ud.at(i);
      t.at(i) = u + d - mid;
    }
    pair<ll, ll> p;
    auto [pu, pd] = ud.at(0);
    p.first = min(pu, pu + pd - t.at(0));
    p.second = max(0LL, pu - t.at(0));
    rep2(i, 1, n) {
      auto [umx, umn] = p;
      ll top = umx + x;
      ll btm = umn - x;
      auto [u, d] = ud.at(i);
      ll ntop = min(u, u + d - t.at(i));
      ll nbtm = max(0LL, u - t.at(i));
      p.first = min(top, ntop);
      p.second = max(btm, nbtm);
      if (p.first < p.second) return {false, 0};
    }
    return {true, reduce(ALL(t))};
  };
  ll ok = 0, ng = mn + 1;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (fc(mid).first)
      ok = mid;
    else
      ng = mid;
  }
  cout << fc(ok).second << endl;
  return 0;
}