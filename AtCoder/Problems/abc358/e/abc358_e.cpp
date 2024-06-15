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

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

int main() {
  int k;
  cin >> k;
  vector<int> c(26);
  rep(i, 26) cin >> c.at(i);
  vector<mint> base(k + 1, 0);
  auto dp = base;
  dp.at(0) = 1;
  combination cb(k + 5);
  rep(p, 26) {
    auto nxdp = dp;
    rep(i, k + 1) {
      rep2(j, 1, c.at(p) + 1) {
        int ni = i + j;
        if (ni > k) break;
        nxdp.at(ni) += dp.at(i) * cb(i + j, i);
      }
    }
    swap(dp, nxdp);
    // rep(i, dp.size()) cerr << dp.at(i).val() << " ";
    // cerr << endl;
  }
  mint ans = reduce(ALL(dp)) - 1;
  cout << ans.val() << endl;
  return 0;
}