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
  int n, p;
  cin >> n >> p;
  mint p100 = (mint)p / 100;
  mint rp100 = (mint)(100 - p) / 100;
  // vector dp(n + 1, vector<mint>(n + 1, 0));
  // mint pw = mint(100).pow(n);
  // dp.front().back() = pw;
  // rep(i, n) {
  //   rrep2(j, 1, n + 1) {
  //     int ni = i + 1;
  //     int nj = j - 1;
  //     dp.at(ni).at(nj) += dp.at(i).at(j) * rp100;
  //     nj = max(0, nj - 1);
  //     dp.at(ni).at(nj) += dp.at(i).at(j) * p100;
  //   }
  // }
  // mint ans = 0;
  // rep(i, n + 1) { ans += i * dp.at(i).front(); }
  // rep(i, n + 1) {
  //   rep(j, n + 1) { cerr << dp.at(i).at(j).val() << " "; }
  //   cerr << endl;
  // }
  // cout << (ans / pw).val() << endl;
  if (n == 1) {
  }
  vector<mint> dp(n + 1, 0);
  cerr << p100.val() << " " << rp100.val() << endl;
  dp.at(n - 1) = rp100.val();
  rrep(i, n - 1) {
    dp.at(i) = (dp.at(i + 1) + 1) * rp100 + (dp.at(i + 2) + 1) * p100;
  }
  cout << dp.front().val() << endl;
  return 0;
}