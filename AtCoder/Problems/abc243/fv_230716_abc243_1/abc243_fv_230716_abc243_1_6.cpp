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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> w(n);
  rep(i, n) cin >> w.at(i);
  combination cb(55);

  vector base(m + 1, vector<mint>(k + 1, 0));
  auto dp = base;
  dp.front().front() = 1;
  for (int now : w) {
    auto nxdp = base;
    mint ml = 1;
    rep(add, k + 1) {
      rep(i, m + 1) {
        int ni = i;
        if (add != 0) ni++;
        if (ni > m) break;
        rep(j, k + 1) {
          int nj = j + add;
          if (nj > k) break;
          nxdp.at(ni).at(nj) += dp.at(i).at(j) * ml * cb(k - j, add);
        }
      }
      ml *= now;
    }
    swap(dp, nxdp);
  }
  mint ans = dp.back().back();
  mint bb = reduce(ALL(w));
  bb = bb.pow(k);
  ans /= bb;
  cout << ans.val() << endl;
  return 0;
}