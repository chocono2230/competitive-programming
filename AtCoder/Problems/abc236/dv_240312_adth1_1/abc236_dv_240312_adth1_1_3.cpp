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
  int n;
  cin >> n;
  n *= 2;
  vector a(n, vector<int>(n));
  rep(i, n) {
    rep2(j, i + 1, n) {
      int in;
      cin >> in;
      a.at(i).at(j) = a.at(j).at(i) = in;
    }
  }

  vector<bool> chk(n, false);
  auto rc = [&](const auto &self, int lv, ll x) -> ll {
    if (lv == n) {
      return x;
    }
    if (chk.at(lv)) return self(self, lv + 1, x);
    ll res = 0;
    chk.at(lv) = true;
    rep2(i, lv + 1, n) {
      if (chk.at(i)) continue;
      chk.at(i) = true;
      ll nx = (x ^ a.at(lv).at(i));
      ll r = self(self, lv + 1, nx);
      res = max(res, r);
      chk.at(i) = false;
    }
    chk.at(lv) = false;
    return res;
  };
  cout << rc(rc, 0, 0) << endl;
  return 0;
}