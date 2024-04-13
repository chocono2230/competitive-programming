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
  vector a(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> a.at(i).at(j);
  auto jg = [](int k) {
    vector chk(3, vector<bool>(3, false));
    rep(idx, 9) {
      if ((k & (1 << idx)) == 0) continue;
      chk.at(idx / 3).at(idx % 3) = true;
    }
    rep(i, 3) {
      bool x = false;
      rep(j, 3) {
        if (!chk.at(i).at(j)) x = true;
      }
      if (!x) return true;
    }
    rep(j, 3) {
      bool x = false;
      rep(i, 3) {
        if (!chk.at(i).at(j)) x = true;
      }
      if (!x) return true;
    }
    bool x = false;
    rep(i, 3) {
      if (!chk.at(i).at(i)) x = true;
    }
    if (!x) return true;
    x = false;
    rep(i, 3) {
      if (!chk.at(2 - i).at(i)) x = true;
    }
    if (!x) return true;
    return false;
  };
  auto tow = [&](int info) {
    int t = 0, a = 0;
    int idx = 0;
    while (info != 0) {
      int p = info % 3;
      if (p == 1) {
        t |= (1 << idx);
      }
      if (p == 2) {
        a |= (1 << idx);
      }
      info /= 3;
      idx++;
    }
    if (jg(t)) return 1;
    if (jg(a)) return 2;
    return 0;
  };
  vector<int> memo(20000, -1);
  auto rc = [&](const auto &self, int info, int tu) -> int {
    if (memo.at(info) != -1) return memo.at(info);
    if (tu == 9) {
      auto r = tow(info);
      if (r != 0) {
        if (r == 1)
          return memo.at(info) = 1;
        else
          return memo.at(info) = 0;
      }
      ll t = 0, ao = 0;
      int idx = 0;
      int mi = info;
      while (info != 0) {
        int p = info % 3;
        if (p == 1)
          t += a.at(idx / 3).at(idx % 3);
        else if (p == 2)
          ao += a.at(idx / 3).at(idx % 3);
        info /= 3;
        idx++;
      }
      r = 1;
      if (ao > t) r = 0;
      return memo.at(mi) = r;
    }
    int add = (tu % 2) + 1;
    int base = 1;
    int ii = info;
    rep(idx, 9) {
      if (ii % 3 == 0) {
        int nxinfo = info;
        nxinfo += base * add;
        auto r = self(self, nxinfo, tu++);
        if (r == 0) {
          return memo.at(info) = 1;
        }
      }
      base *= 3;
      ii /= 3;
    }
    return memo.at(info) = 0;
  };
  auto p = rc(rc, 0, 0);
  if (p == 1)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}