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
  int n, x;
  cin >> n >> x;
  x--;
  vector base(n + 1, vector(1 << x, vector<mint>(1 << x, 0)));
  int flg = (x == 0 ? 0 : (1 << (x - 1)));
  auto dp = base;
  dp.front().front().front() = 1;
  rep(i, n) {
    auto nxdp = base;
    int zz = (1 << x);
    rep(m, i + 1) rep(p, zz) rep(q, zz) {
      auto now = dp.at(m).at(p).at(q);
      if (now == 0) continue;
      int pc = m - __builtin_popcount(p);
      int qc = m - __builtin_popcount(q);
      nxdp.at(m + 1).at((p >> 1) | flg).at((q >> 1) | flg) += now;
      nxdp.at(m).at(p >> 1).at((q >> 1) | flg) += now * qc;
      nxdp.at(m).at((p >> 1) | flg).at(q >> 1) += now * pc;
      if (m != 0) nxdp.at(m - 1).at((p >> 1)).at((q >> 1)) += now * pc * qc;
    }
    swap(dp, nxdp);
  }
  cout << dp.front().front().front().val() << endl;
  return 0;
}