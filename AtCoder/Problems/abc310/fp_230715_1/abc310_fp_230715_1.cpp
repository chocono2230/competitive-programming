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
  vector dp(n + 1, vector<mint>(1 << 11, 0));
  dp.front().at(1) = 1;
  rep(i, n) {
    int in;
    cin >> in;
    mint ml = (mint)1 / in;
    int ni = i + 1;
    rep(bit, 1 << 11) {
      if (dp.at(i).at(bit) == 0) continue;
      rep2(add, 1, min(in, 10) + 1) {
        int nxbit = bit;
        rep(z, 11) {
          if (z + add > 10) break;
          if ((bit & (1 << z)) != 0) {
            nxbit |= (1 << (z + add));
          }
        }
        dp.at(ni).at(nxbit) += dp.at(i).at(bit) * ml;
      }
      int z = in - 10;
      if (z <= 0) continue;
      dp.at(ni).at(bit) += dp.at(i).at(bit) * ml * z;
    }
  }
  mint ans = 0;
  rep(bit, 1 << 11) {
    if ((bit & (1 << 10)) == 0) continue;
    ans += dp.back().at(bit);
  }
  cout << ans.val() << endl;
  return 0;
}