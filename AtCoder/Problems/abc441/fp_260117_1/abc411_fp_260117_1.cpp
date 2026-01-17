#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(ri, n) for (int ri = (int)(n - 1); ri >= 0; ri--)
#define rep2(i, x, n) for (int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri, x, n) for (int ri = (int)(n - 1); ri >= (int)(x); ri--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> pv(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    pv.at(i) = {a, b};
  }

  vector dp1(n + 1, vector<ll>(m + 1, 0));
  rep(i, n) {
    auto [p, v] = pv.at(i);
    rep(j, m + 1) {
      chmax(dp1.at(i + 1).at(j), dp1.at(i).at(j));
      if (j + p <= m) chmax(dp1.at(i + 1).at(j + p), dp1.at(i).at(j) + v);
    }
  }
  vector dp2(n + 1, vector<ll>(m + 1, 0));
  rrep(i, n) {
    auto [p, v] = pv.at(i);
    rrep(j, m + 1) {
      chmax(dp2.at(i).at(j), dp2.at(i + 1).at(j));
      if (j - p >= 0) chmax(dp2.at(i).at(j - p), dp2.at(i + 1).at(j) + v);
    }
  }
  ll mx = dp1.back().back();
  string ans(n, 'B');
  rep(i, n) {
    auto [p, v] = pv.at(i);
    bool f1 = false, f2 = false;
    rep(j, m + 1) {
      ll pr = 0, nx = 0;
      pr = dp1.at(i).at(j);
      nx = dp2.at(i + 1).at(j);
      if (pr + nx == mx) f1 = true;
    }
    if (!f1) ans.at(i) = 'A';
    rep(j, m + 1) {
      if (j + p > m) break;
      ll pr = 0, nx = 0;
      pr = dp1.at(i).at(j);
      nx = dp2.at(i + 1).at(j + p);
      if (pr + nx + v == mx) f2 = true;
    }
    if (!f2) ans.at(i) = 'C';
  }
  cout << ans << endl;
  return 0;
}