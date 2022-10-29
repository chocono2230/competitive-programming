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
  int n, m, k;
  cin >> n >> m >> k;
  vector<mint> base(n + 1, 0);
  auto dp = base;
  mint ans = 0, p = 1;
  dp.front() = 1;
  rep(i, k) {
    auto nxdp = base;
    rep(i, n) {
      rep(j, m) {
        int ni = i + j + 1;
        int d = ni - n;
        if (d > 0) {
          ni = n - d;
        }
        nxdp.at(ni) += dp.at(i);
      }
    }
    swap(nxdp, dp);
    mint sum = 0;
    for (auto i : dp) sum += i;
    if (sum == 0) break;
    mint add = dp.back() / sum;
    add *= p;
    ans += add;
    p *= (sum - dp.back()) / sum;
    dp.back() = 0;
  }
  cout << ans.val() << endl;
  return 0;
}