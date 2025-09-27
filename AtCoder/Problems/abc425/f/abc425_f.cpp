#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main() {
  int n;
  cin >> n;
  string t;
  cin >> t;
  int sz = 1;
  rep(i, n) sz *= 2;
  auto i2s = [&](int bit) {
    string res;
    rep(i, n) {
      if ((bit & (1 << i)) == 0) continue;
      res.push_back(t.at(i));
    }
    return res;
  };
  vector<mint> dp(sz, 0);
  dp.back() = 1;
  rrep2(bit, 1, sz) {
    if (dp.at(bit) == 0) continue;
    int pidx = 0;
    auto ss = i2s(bit);
    // cerr << ss << endl;
    rep(i, n) {
      if ((bit & (1 << i)) == 0) continue;
      int nxbit = bit;
      nxbit ^= (1 << i);
      pidx++;
      if (pidx != 1 && ss.at(pidx - 2) == ss.at(pidx - 1)) continue;
      dp.at(nxbit) += dp.at(bit);
    }
  }
  cout << dp.front().val() << endl;
  return 0;
}