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
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> c(n);
  vector a(n, vector<int>(k));
  rep(i, n) {
    cin >> c.at(i);
    rep(j, k) cin >> a.at(i).at(j);
  }
  const ll INF = 1e18;
  auto fc = [=](int idx) -> vector<int> {
    vector<int> res(k);
    rep(i, k) {
      res.at(i) = idx % (p + 1);
      idx /= (p + 1);
    }
    return res;
  };
  auto rfc = [=](vector<int> &v) -> int {
    int res = 0;
    rrep(i, k) {
      res *= (p + 1);
      res += v.at(i);
    }
    return res;
  };
  vector<ll> base(7776, INF);
  auto dp = base;
  dp.front() = 0;
  rep(i, n) {
    int nc = c.at(i);
    auto &na = a.at(i);
    auto nxdp = base;
    rep(i, nxdp.size()) {
      nxdp.at(i) = min(nxdp.at(i), dp.at(i));
      auto v = fc(i);
      rep(i, na.size()) v.at(i) = min(p, v.at(i) + na.at(i));
      int nidx = rfc(v);
      nxdp.at(nidx) = min(nxdp.at(nidx), dp.at(i) + nc);
    }
    swap(dp, nxdp);
  }
  vector<int> v(5, 0);
  rep(i, k) v.at(i) = p;
  int idx = rfc(v);
  ll ans = dp.at(idx);
  if (ans == INF) ans = -1;
  cout << ans << endl;
  return 0;
}