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
  int n, k;
  cin >> n >> k;
  using pp = pair<ll, int>;
  const ll INF = 1e18;
  vector<pair<pp, pp>> base(k + 1, {{-INF, -1}, {-INF, -1}});
  auto dp = base;
  dp.front() = {{0, 0}, {-INF, -1}};
  rep(i, n) {
    int c, v;
    cin >> c >> v;
    auto nxdp = base;
    auto ad = [&](pair<pp, pp> &l, const pp &add) {
      if (l.first.second != add.second && l.first.first < add.first) {
        l.second = l.first;
        l.first = add;
        return;
      }
      if (l.first.second == add.second) {
        if (l.first.first < add.first) l.first = add;
        return;
      }
      if (l.second.first < add.first) {
        l.second = add;
      }
    };
    rep(i, k + 1) {
      auto upd = [&](pair<pp, pp> &l, pp &nx, bool flg) {
        if (nx.first == -INF) return;
        if (flg) {
          if (nx.second != c) {
            auto p = nx;
            p.first += v;
            p.second = c;
            ad(l, p);
          }
        } else {
          ad(l, nx);
        }
      };
      upd(nxdp.at(i), dp.at(i).first, true);
      upd(nxdp.at(i), dp.at(i).second, true);
      if (i != k) {
        upd(nxdp.at(i + 1), dp.at(i).first, false);
        upd(nxdp.at(i + 1), dp.at(i).second, false);
      }
    }
    swap(dp, nxdp);
    // rep(i, k + 1) {
    //   auto pp = dp.at(i);
    //   auto r = [&](ll x) -> ll {
    //     if (x == -INF) return -1;
    //     return x;
    //   };
    //   cerr << r(pp.first.first) << ":" << r(pp.first.second) << "|"
    //        << r(pp.second.first) << ":" << r(pp.second.second) << "  ";
    // }
    // cerr << endl;
  }
  auto a = dp.back();
  ll ans = a.first.first;
  if (ans == -INF) ans = -1;
  cout << ans << endl;
  return 0;
}