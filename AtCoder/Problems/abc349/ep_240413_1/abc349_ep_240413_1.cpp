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
  vector aa(3, vector<int>(3));
  rep(i, 3) rep(j, 3) { cin >> aa.at(i).at(j); }
  auto i2t = [&](int info) {
    vector res(3, vector<int>(3, 0));
    rep(i, 3) rep(j, 3) {
      res.at(i).at(j) = info % 3;
      info /= 3;
    }
    return res;
  };
  vector<int> memo(200000, -1);
  auto rc = [&](const auto &self, int turn, const int info) -> int {
    if (memo.at(info) != -1) return memo.at(info);
    auto tb = i2t(info);
    auto jg = [&](int p) {
      bool x = false;
      rep(i, 3) {
        x = false;
        rep(j, 3) {
          if (tb.at(i).at(j) != p) x = true;
        }
        if (!x) return true;
      }
      rep(j, 3) {
        x = false;
        rep(i, 3) {
          if (tb.at(i).at(j) != p) x = true;
        }
        if (!x) return true;
      }
      x = false;
      rep(i, 3) {
        if (tb.at(i).at(i) != p) x = true;
      }
      if (!x) return true;
      x = false;
      rep(i, 3) {
        if (tb.at(2 - i).at(i) != p) x = true;
      }
      if (!x) return true;
      return false;
    };
    int p = (turn % 2) + 1;
    int pv = ((turn + 1) % 2) + 1;
    if (jg(p)) return memo.at(info) = 1;
    if (jg(pv)) return memo.at(info) = 0;
    if (turn == 9) {
      ll t = 0, a = 0;
      rep(i, 3) rep(j, 3) {
        if (tb.at(i).at(j) == 1) t += aa.at(i).at(j);
        if (tb.at(i).at(j) == 2) a += aa.at(i).at(j);
      }
      int r = 1;
      if (t > a) r = 0;
      return memo.at(info) = r;
    }
    int base = 1;
    int add = (turn % 2) + 1;
    int pinfo = info;
    rep(idx, 9) {
      if (pinfo % 3 == 0) {
        int nxinfo = info;
        nxinfo += base * add;
        auto r = self(self, turn + 1, nxinfo);
        if (r == 0) return memo.at(info) = 1;
      }
      base *= 3;
      pinfo /= 3;
    }
    return memo.at(info) = 0;
  };
  auto r = rc(rc, 0, 0);
  if (r == 1)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}