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
  vector dp(n + 1, vector<mint>(n + 1, 0));
  dp.front().front() = 1;
  rep(i, n) {
    int ni = i + 1;
    rep2(j, 1, i + 2) {
      dp.at(ni).at(j) += dp.at(i).at(j - 1);
      int z = j - (((i + 1) + m - 1) / m - 1);
      if (z < 0) z = 0;
      dp.at(ni).at(j) += dp.at(i).at(j) * z;
    }
  }
  // rep(i, n + 1) {
  //   rep(j, n + 1) cerr << dp.at(i).at(j).val() << " ";
  //   cerr << endl;
  // }
  rep(i, n) { cout << dp.back().at(i + 1).val() << endl; }
  return 0;
}