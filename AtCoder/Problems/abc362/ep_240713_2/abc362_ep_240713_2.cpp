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
  map<int, int> mp;
  vector gr(n, vector<int>(n, -1));
  rep(i, n) rep2(j, i + 1, n) { mp[a.at(j) - a.at(i)] = -1; }
  int sz = 0;
  for (auto &p : mp) p.second = sz++;
  rep(i, n) rep2(j, i + 1, n) gr.at(i).at(j) = mp[a.at(j) - a.at(i)];

  vector dp(n, vector(n + 1, vector<mint>(sz, 0)));
  rrep(i, n) rep2(j, i + 1, n) {
    int d = gr.at(i).at(j);
    dp.at(i).at(2).at(d) += 1;
    rep2(k, 3, n + 1) { dp.at(i).at(k).at(d) += dp.at(j).at(k - 1).at(d); }
  }
  vector<mint> ans(n + 1, 0);
  ans.at(1) = n;
  rep(i, n) rep(j, n + 1) rep(k, sz) ans.at(j) += dp.at(i).at(j).at(k);
  rep2(i, 1, n + 1) {
    if (i != 1) cout << " ";
    cout << ans.at(i).val();
  }
  cout << endl;
  return 0;
}