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
  ll n;
  cin >> n;
  map<ll, mint> dp;
  dp[1] = 1;
  mint d5 = (mint)1 / (mint)5;
  mint sum = 0, ans = 0;
  while (!dp.empty()) {
    auto itr = dp.begin();
    auto [now, co] = *itr;
    rep2(add, 2, 7) {
      ll nx = now * add;
      if (nx < n) {
        dp[nx] += co * d5;
      } else {
        sum += co * d5;
        if (nx == n) ans += co * d5;
      }
    }
    dp.erase(dp.begin());
  }
  ans /= sum;
  cout << ans.val() << endl;
  return 0;
}