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
  int n, m;
  cin >> n >> m;
  int b, w;
  cin >> b >> w;

  combination cb(n * m + 2);
  auto fc = [&](vector<vector<mint>> &dp, int x) -> void {
    int mxn = dp.size(), mxm = dp.front().size();
    rep2(i, 1, mxn) rep2(j, 1, mxm) {
      dp.at(i).at(j) = cb(i * j, x);
      rep2(ii, 1, i + 1) rep2(jj, 1, j + 1) {
        if (ii == i && jj == j) continue;
        dp.at(i).at(j) -= cb(i, ii) * cb(j, jj) * dp.at(ii).at(jj);
      }
    }
  };
  vector dpw(n, vector<mint>(m, 0));
  auto dpb = dpw;
  fc(dpw, w);
  fc(dpb, b);

  mint ans = 0;
  rep2(i, 1, n + 1) rep2(j, 1, n - i + 1) rep2(k, 1, m) rep2(l, 1, m - k + 1) {
    ans += cb(n, i) * cb(n - i, j) * cb(m, k) * cb(m - k, l) * dpb.at(i).at(k) *
           dpw.at(j).at(l);
  }
  cout << ans.val() << endl;
  return 0;
}