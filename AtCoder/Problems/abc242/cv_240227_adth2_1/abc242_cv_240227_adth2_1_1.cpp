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
  int n;
  cin >> n;
  vector<mint> base(9, 0);
  auto dp = base;
  rep(i, 9) dp.at(i) = 1;
  rep(_i, n - 1) {
    auto nxdp = base;
    rep(i, 9) {
      nxdp.at(i) += dp.at(i);
      if (i != 0) nxdp.at(i - 1) += dp.at(i);
      if (i != 8) nxdp.at(i + 1) += dp.at(i);
    }
    swap(dp, nxdp);
  }
  auto ans = reduce(ALL(dp));
  cout << ans.val() << endl;
  return 0;
}