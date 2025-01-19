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
  int n;
  ll m;
  cin >> n >> m;
  vector<ll> p(n);
  rep(i, n) cin >> p.at(i);
  vector<ll> cc(n, 0);
  ll z = 0;
  ll ans = 0;
  auto fc = [&](ll mid) {
    ll sum = 0;
    ans = 0;
    rep(i, n) {
      ll c = ((double)mid / p.at(i) + 1) / 2 - 3;
      while (1) {
        if ((2 * (c + 1) - 1) * p.at(i) > mid) break;
        c++;
      }
      cc.at(i) = c;
      if (c != 0 && c > LLONG_MAX / c) return false;
      if (c * c > LLONG_MAX / p.at(i)) return false;
      sum += c * c * p.at(i);
      ans += c;
      if (sum > m) return false;
    }
    z = m - sum;
    return true;
  };
  ll ok = 0, ng = 1e18;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (fc(mid))
      ok = mid;
    else
      ng = mid;
  }
  fc(ok);
  // cerr << ok << endl;
  vector<ll> mns(n);
  rep(i, n) { mns.at(i) = (2 * (cc.at(i) + 1) - 1) * p.at(i); }
  sort(ALL(mns));
  rep(i, n) {
    z -= mns.at(i);
    if (z < 0) break;
    ans++;
  }
  cout << ans << endl;
  return 0;
}