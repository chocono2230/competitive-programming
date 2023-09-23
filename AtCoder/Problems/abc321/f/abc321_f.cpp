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
  int q, k;
  cin >> q >> k;
  vector dp(q + 1, vector<mint>(k + 1, 0));
  dp.front().front() = 1;
  map<int, vector<int>> mp;
  rep(i, q) {
    char c;
    int x;
    cin >> c >> x;
    int ni = i + 1;
    if (c == '+') {
      rep(j, k + 1) {
        dp.at(ni).at(j) += dp.at(i).at(j);
        if (j + x <= k) {
          dp.at(ni).at(j + x) += dp.at(i).at(j);
        }
      }
      mp[x].push_back(i);
    } else {
      int idx = mp[x].back();
      mp[x].pop_back();
      rep(j, k + 1) {
        dp.at(ni).at(j) += dp.at(i).at(j);
        if (j + x <= k) {
          dp.at(ni).at(j + x) -= dp.at(idx).at(j);
        }
      }
    }
    rep(j, k + 1) cerr << dp.at(ni).at(j).val() << " ";
    cerr << endl;
    cout << dp.at(ni).back().val() << endl;
  }
  return 0;
}