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
using mint = modint;

int main() {
  int n, p;
  cin >> n >> p;
  modint::set_mod(p);
  vector base(n, vector<mint>(2, 0));
  auto dp = base;
  dp.at(0).at(0) = 1;
  dp.at(1).at(1) = 1;
  rep(_i, n - 1) {
    auto nxdp = base;
    rep(i, n) {
      nxdp.at(i).at(0) += dp.at(i).at(0);
      if (i < n - 1) {
        nxdp.at(i + 1).at(0) += dp.at(i).at(0) * 3;
      }
      if (i < n - 2) {
        nxdp.at(i + 2).at(1) += dp.at(i).at(0) * 2;
      }

      nxdp.at(i).at(0) += dp.at(i).at(1);
      if (i < n - 1) {
        nxdp.at(i + 1).at(1) += dp.at(i).at(1);
      }
    }
    swap(dp, nxdp);
  }

  rep2(i, 1, n) {
    if (i != 1) cout << " ";
    cout << dp.at(i).at(0).val();
  }
  cout << endl;
  return 0;
}