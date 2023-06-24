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
  int n, m;
  cin >> n >> m;
  if (m == 2) {
    if (n % 2 == 0)
      cout << 2 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  // if (n == 2) {
  //   mint ans = m;
  //   ans *= m - 1;
  //   cout << ans.val() << endl;
  //   return 0;
  // }

  // mint ans = m;
  // int now = 1;
  // if (n % 2 == 0) {
  //   ans *= m - 1;
  //   now++;
  // }
  // while (now != n - 2) {
  //   ans *= m - 1;
  //   ans *= m - 1;
  //   now += 2;
  // }

  // mint ans = 1;
  // rep(i, n - 1) ans *= m - 1;
  // mint del = 1;
  // del *= mint(m - 1).pow(n - 2);
  // cerr << del.val() << endl;
  // ans -= del;

  // if (n == 3) {
  //   ans *= m - 2;
  //   cout << ans.val() << endl;
  //   return 0;
  // }
  // cerr << ans.val() << endl;
  // ans *= (mint(m - 2) * mint(m - 1) + mint(m - 1) * mint(1)) / mint(m);

  vector dp(n, vector<mint>(2, 0));
  dp.front().front() = 1;
  rep(i, n - 1) {
    int ni = i + 1;
    dp.at(ni).at(1) += dp.at(i).at(0) * (m - 1);
    dp.at(ni).at(0) += dp.at(i).at(1);
    dp.at(ni).at(1) += dp.at(i).at(1) * (m - 2);
  }
  mint ans = dp.back().back();
  ans *= m;

  cout << ans.val() << endl;
  return 0;
}