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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  map<int, int> mp;
  rep(i, n) rep2(j, i + 1, n) {
    ll d = a.at(j) - a.at(i);
    mp[d] = -1;
  }
  int sz = 0;
  for (auto &p : mp) {
    p.second = sz++;
  }
  vector<mint> ans(n + 1, 0);
  for (auto [d, _] : mp) {
    vector dp(n + 1, vector<mint>(n + 1, 0));
    rep(i, n) {
      rep(j, i) {
        if (a.at(i) - a.at(j) != d) continue;
        dp.at(i).at(1)++;
      }
    }
  }
  ans.at(1) = n;
  rep2(i, 1, n + 1) {
    if (i != 1) cout << " ";
    cout << ans.at(i).val();
  }
  cout << endl;
  return 0;
}