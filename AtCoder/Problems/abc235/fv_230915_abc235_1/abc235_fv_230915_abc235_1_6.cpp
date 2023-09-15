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
using mint = modint998244353;

int main() {
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<int> c(m);
  rep(i, m) cin >> c.at(i);
  int msk = 0;
  for (auto now : c) msk |= (1 << now);
  vector<mint> pw(s.size(), 1);
  rrep(i, pw.size() - 1) pw.at(i) = pw.at(i + 1) * 10;
  vector base(1 << 10, vector<pair<mint, mint>>(2, {0, 0}));
  auto dp = base;
  rep(i, s.size()) {
    if (i == 0)
      dp.at(0).at(0).second = 1;
    else
      dp.at(0).at(1).second = 1;
    auto nxdp = base;
    int p = s.at(i) - '0';
    rep(bit, 1 << 10) {
      rep(k, 2) {
        if (dp.at(bit).at(k).second == 0) continue;
        rep(m, 10) {
          if (m == 0 && bit == 0) continue;
          int nk = k;
          if (k == 0) {
            if (m > p) break;
            if (m < p) nk = 1;
          }
          int nxbit = (bit | (1 << m));
          nxdp.at(nxbit).at(nk).second += dp.at(bit).at(k).second;
          nxdp.at(nxbit).at(nk).first +=
              dp.at(bit).at(k).first + dp.at(bit).at(k).second * pw.at(i) * m;
        }
      }
    }
    swap(dp, nxdp);
  }

  mint ans = 0;
  rep(i, 1 << 10) {
    if ((i & msk) != msk) continue;
    ans += dp.at(i).at(1).first;
    ans += dp.at(i).at(0).first;
  }
  cout << ans.val() << endl;
  return 0;
}