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
// using mint = double;

int main() {
  int in, k;
  cin >> in >> k;
  if (in == 1) {
    cout << 1 << endl;
    return 0;
  }
  mint n = in;

  vector<mint> base(2, 0);
  auto dp = base;
  dp.front() = 1;
  mint nn = n * n;
  mint z2o = 2 * (n - 1) / nn;
  mint z2z = (nn - 2 * (n - 1)) / nn;
  mint o2z = 2 / nn;
  mint o2o = (nn - 2) / nn;
  rep(i, k) {
    auto nxdp = base;
    nxdp.front() = z2z * dp.front() + o2z * dp.back();
    nxdp.back() = z2o * dp.front() + o2o * dp.back();
    swap(dp, nxdp);
    // cerr << fixed << dp.front() << " " << dp.back() << endl;
  }
  mint ans = dp.front();
  mint ss = n * (n + 1) / 2 - 1;
  ans += dp.back() / (n - 1) * ss;
  cout << ans.val() << endl;
  // cerr << fixed << ans << endl;

  // vector<mint> base(3, 0);
  // auto dp = base;
  // dp.front() = 1;
  // rep(_i, k) {
  //   auto nxdp = base;
  //   rep(i, n) rep(j, n) {
  //     rep(k, n) {
  //       if (k == i)
  //         nxdp.at(k) += dp.at(j) / mint(n * n);
  //       else if (k == j)
  //         nxdp.at(k) += dp.at(i) / mint(n * n);
  //       else
  //         nxdp.at(k) += dp.at(k) / mint(n * n);
  //     }
  //   }
  //   swap(dp, nxdp);
  //   for (auto now : dp) cerr << fixed << now << " ";
  //   cerr << endl;
  //   mint s = reduce(ALL(dp)) - dp.front();
  //   cerr << dp.front() << " " << s << endl;
  // }
  // mint ans = 0;
  // rep(i, n) { ans += dp.at(i) * (i + 1); }
  // cerr << fixed << ans << endl;

  // vector<mint> base(2, 0);
  // auto dp = base;
  // dp.front() = 1;
  // rep(i, k) {
  //   auto nxdp = base;
  //   mint p = 1 / n;
  //   mint q = (n - 1) / n;
  //   nxdp.front() += p * (p * dp.front() + p * dp.back());
  //   nxdp.back() += p * (q * dp.front() + q * dp.back());
  //   nxdp.front() += q * (q * dp.front() + p * dp.back());
  //   nxdp.back() += q * (p * dp.front() + q * dp.back());
  //   swap(dp, nxdp);
  //   cerr << fixed << dp.front() << " " << dp.back() << endl;
  // }
  // mint ans = dp.front();
  // mint ss = n * (n + 1) / 2 - 1;
  // ans += dp.back() / (n - 1) * ss;
  // // cout << ans.val() << endl;
  // cerr << fixed << ans << endl;

  // auto dp = base;
  // dp.front() = 1;
  // mint nn = n * n;
  // mint z2o = mint(n - 1) * 2 / nn;
  // mint o2z = 2 / nn;
  // mint x = ((n - 1) * 2 - 2) / nn;
  // cerr << fixed << z2o << " " << o2z << " " << x << endl;
  // rep(i, k) {
  //   auto nxdp = base;
  //   nxdp.front() = dp.front() * (x + z2o) + dp.back() * o2z;
  //   nxdp.back() = dp.front() * z2o + dp.back() * (x + o2z);
  //   swap(dp, nxdp);
  // }
  // cerr << dp.front() << " " << dp.back() << endl;
  return 0;
}