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
  ll n;
  cin >> n;
  string sn = to_string(n);
  vector<ll> pw(sn.size(), 1);
  rrep(i, pw.size() - 1) pw.at(i) = pw.at(i + 1) * 10;
  vector base(2, vector(130, vector<ll>(130, 0)));
  ll ans = 0;
  rep2(p, 1, 130) {
    auto dp = base;
    dp.at(1).at(0).at(p) = 1;
    rep(i, sn.size()) {
      int now = sn.at(i) - '0';
      auto nxdp = base;
      rep(k, p) rep(l, p + 1) rep(add, 10) {
        if (dp.at(0).at(k).at(l) == 0) continue;
        if (l - add < 0) continue;
        int nl = l - add;
        int nk = ((ll)k + pw.at(i) * add) % p;
        nxdp.at(0).at(nk).at(nl) += dp.at(0).at(k).at(l);
      }
      rep(k, p) rep(l, p + 1) rep(add, 10) {
        if (dp.at(1).at(k).at(l) == 0) continue;
        if (l - add < 0) continue;
        int nj = 1;
        if (add > now) break;
        if (add < now) nj = 0;
        int nl = l - add;
        int nk = ((ll)k + pw.at(i) * add) % p;
        nxdp.at(nj).at(nk).at(nl) += dp.at(1).at(k).at(l);
      }
      swap(dp, nxdp);
    }
    ans += dp.at(0).at(0).at(0);
    ans += dp.at(1).at(0).at(0);
  }
  cout << ans << endl;
  return 0;
}