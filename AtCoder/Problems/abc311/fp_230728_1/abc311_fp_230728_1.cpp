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
  vector<string> s(n);
  rep(i, n) cin >> s.at(i);
  rep(i, n - 1) rep(j, m) {
    if (s.at(i).at(j) == '#') {
      s.at(i + 1).at(j) = '#';
      if (j != m - 1) s.at(i + 1).at(j + 1) = '#';
    }
  }
  vector<string> t(n + m - 1, string(m, '#'));
  rep(i, n) rep(j, m) { t.at(i + (m - 1 - j)).at(j) = s.at(i).at(j); }
  // for (auto ss : t) cerr << ss << endl;
  vector dp(n + m, vector<mint>(m + 1, 0));
  dp.front().back() = 1;
  rep(i, n + m - 1) {
    int ni = i + 1;
    mint sum = 0;
    rrep(j, m + 1) {
      sum += dp.at(i).at(j);
      if (j != 0 && j != m - 1 - i && t.at(i).at(j - 1) == '#') continue;
      if (j < m - 1 - i) break;
      dp.at(ni).at(j) += sum;
    }
  }
  // rep(i, n + m) {
  //   rep(j, m + 1) cerr << dp.at(i).at(j).val() << " ";
  //   cerr << endl;
  // }
  mint ans = reduce(ALL(dp.back()));
  cout << ans.val() << endl;
  return 0;
}