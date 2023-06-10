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
using mint = modint1000000007;

vector<vector<mint>> matrix_mul(const vector<vector<mint>> &p,
                                const vector<vector<mint>> &q) {
  const int n = p.size();
  vector res(n, vector<mint>(n, 0));
  rep(k, n) rep(i, n) rep(j, n) {
    res.at(i).at(j) += p.at(i).at(k) * q.at(k).at(j);
  }
  return res;
}

vector<vector<mint>> matrix_exp(const vector<vector<mint>> &now, ll lv) {
  const int n = now.size();
  if (lv == 0) {
    vector res(n, vector<mint>(n, 0));
    rep(i, n) res.at(i).at(i) = 1;
    return res;
  }
  if (lv == 1) return now;
  if (lv % 2 == 1) return matrix_mul(now, matrix_exp(now, lv - 1));
  auto r = matrix_exp(now, lv / 2);
  return matrix_mul(r, r);
}

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector gr(n, vector<int>(n, 0));
  rep(i, n) rep(j, n) cin >> gr.at(i).at(j);
  vector dp(n, vector<mint>(n, 0));
  rep(i, n) rep(j, n) dp.at(i).at(j) = gr.at(i).at(j);
  auto r = matrix_exp(dp, k);
  mint ans = 0;
  rep(i, n) ans += reduce(ALL(r.at(i)));
  cout << ans.val() << endl;
  return 0;
}