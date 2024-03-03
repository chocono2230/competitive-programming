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
  int v1, v2, v3;
  cin >> v1 >> v2 >> v3;
  const int INF = 1001001001;
  auto fc = [&](vector<vector<int>> &v) {
    auto c3 = [&]() {
      auto cmx = [&](int idx) {
        int res = -INF;
        rep(now, 3) res = max(res, v.at(now).at(idx));
        return res;
      };
      auto cmn = [&](int idx) {
        int res = INF;
        rep(now, 3) res = min(res, v.at(now).at(idx));
        return res;
      };
      int d0 = max(0, (cmn(0) + 7) - cmx(0));
      int d1 = max(0, (cmn(1) + 7) - cmx(1));
      int d2 = max(0, (cmn(2) + 7) - cmx(2));
      return d0 * d1 * d2;
    };
    auto c2 = [&](int i1, int i2, int cv3) {
      auto cmx = [&](int idx) {
        return max(v.at(i1).at(idx), v.at(i2).at(idx));
      };
      auto cmn = [&](int idx) {
        return min(v.at(i1).at(idx), v.at(i2).at(idx));
      };
      int d0 = max(0, (cmn(0) + 7) - cmx(0));
      int d1 = max(0, (cmn(1) + 7) - cmx(1));
      int d2 = max(0, (cmn(2) + 7) - cmx(2));
      return d0 * d1 * d2 - cv3;
    };
    int cv1 = 0, cv2 = 0, cv3 = 0;
    cv3 = c3();
    cv2 = c2(0, 1, cv3) + c2(1, 2, cv3) + c2(2, 0, cv3);
    cv1 = 7 * 7 * 7 * 3 - cv3 * 3 - cv2 * 2;
    return cv3 == v3 && cv2 == v2 && cv1 == v1;
  };

  vector vv(3, vector<int>(3, 0));
  auto rc = [&](const auto &self, int lv) -> bool {
    if (lv == 2) {
      return fc(vv);
    }
    rep2(a, -7, 8) rep2(b, -7, 8) rep2(c, -7, 8) {
      vv.at(lv).at(0) = a;
      vv.at(lv).at(1) = b;
      vv.at(lv).at(2) = c;
      auto r = self(self, lv + 1);
      if (r) return true;
    }
    return false;
  };
  if (rc(rc, 0)) {
    cout << "Yes" << endl;
    bool f = false;
    rep(i, 3) rep(j, 3) {
      if (f) cout << " ";
      cout << vv.at(i).at(j);
      f = true;
    }
    cout << endl;
  } else
    cout << "No" << endl;
  return 0;
}