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

int main() {
  ll n;
  int m;
  cin >> n >> m;
  int a, b;
  cin >> a >> b;
  vector<pair<ll, ll>> lr(m);
  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    l--;
    lr.at(i) = {l, r};
    if (r - l >= 20) {
      cout << "No" << endl;
      return 0;
    }
  }
  vector<bool> chk(m, false);
  rep(i, m - 1) {
    if (lr.at(i).second + 1000 < lr.at(i + 1).first) {
      chk.at(i + 1) = true;
    }
  }
  if (lr.front().first > 1000) chk.at(0) = true;
  ll base = 0;
  rep(i, m) {
    // cerr << i << endl;
    if (chk.at(i)) {
      base = lr.at(i).first - 1000;
    }
    int nx = m;
    rep2(j, i + 1, m) {
      if (chk.at(j)) {
        nx = j;
        break;
      }
    }
    int sz = lr.at(nx - 1).second - base;
    bool flg = false;
    if (nx == m && n - lr.back().second < 1000) {
      sz = n - base;
      flg = true;
    }
    vector<bool> ng(sz, false);
    rep2(j, i, nx) {
      int l = lr.at(j).first - base;
      int r = lr.at(j).second - base;
      rep2(k, l, r) { ng.at(k) = true; }
    }
    vector<bool> dp(sz, false);
    if (i == 0 && !chk.at(0)) {
      dp.at(0) = true;
    } else {
      rep(j, min(1000, sz)) { dp.at(j) = true; }
    }
    bool ok = false;
    rep(j, sz) {
      if (!dp.at(j)) continue;
      rep2(add, a, b + 1) {
        int nj = j + add;
        if (nj >= sz) {
          if (!flg) {
            ok = true;
          }
          break;
        }
        if (ng.at(nj)) continue;
        dp.at(nj) = true;
      }
      if (ok) break;
    }
    if (flg && dp.back()) ok = true;
    if (!ok) {
      cout << "No" << endl;
      return 0;
    }
    i = nx - 1;
  }
  cout << "Yes" << endl;
  return 0;
}