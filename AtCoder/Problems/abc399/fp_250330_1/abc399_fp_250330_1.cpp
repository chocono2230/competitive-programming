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

mint calcNumOfCombination_mint(mint n, mint r) {
  mint num = 1;
  for (mint i = 1; i.val() <= r.val(); i += 1) {
    num = num * (n - i + 1) / i;
  }
  return num;
}

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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  combination cb(k + 5);
  vector base(k + 1, vector<mint>(3, 0));
  auto dp = base;
  dp.front().front() = 1;
  for (auto now : a) {
    auto nxdp = base;
    rep(i, k + 1) rep(j, 3) {
      nxdp.at(i).at(j) += dp.at(i).at(j);
      if (j != 2) {
        dp.at(i).at(j + 1) += dp.at(i).at(j);
      }
      if (j != 1) continue;
      rep2(ni, i + 1, k + 1) {
        mint add = dp.at(i).at(j);
        add *= cb(k - i, ni - i);
        add *= mint(now).pow(ni - i);
        // cerr << i << " " << j << " " << ni << " " << add.val() << endl;
        nxdp.at(ni).at(j) += add;
      }
    }
    // rep(i, k + 1) {
    //   rep(j, 3) cerr << nxdp.at(i).at(j).val() << " ";
    //   cerr << endl;
    // }
    // cerr << endl;
    swap(dp, nxdp);
  }
  cout << (dp.back().back() + dp.back().at(1)).val() << endl;
  return 0;
}