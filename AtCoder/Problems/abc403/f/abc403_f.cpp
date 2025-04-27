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
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  const int INF = 1001001001;
  vector dp(n + 1, vector<int>(2, INF));
  vector memo(n + 1,
              vector<tuple<int, int, int, int, int>>(2, {-1, -1, -1, -1, -1}));
  rep2(i, 1, n + 1) { dp.at(i).at(1) = i * 2 - 1; }
  rep2(i, 2, n + 1) { memo.at(i).at(1) = {0, i - 1, 1, 1, 0}; }
  memo.at(2).at(1) = {0, 1, 0, 1, 0};
  int p = 1, co = 1;
  while (p <= n + 1) {
    dp.at(p).at(0) = co;
    memo.at(p).at(0) = {2, co, -1, -1, -1};
    p *= 10;
    p++;
    co++;
  }
  rep2(mx, 1, n + 1) {
    rep2(i, 1, mx) {
      int j = mx - i;
      rep(k1, 2) rep(k2, 2) {
        if (dp.at(mx).at(1) > dp.at(i).at(k1) + dp.at(j).at(k2) + 1) {
          dp.at(mx).at(1) = dp.at(i).at(k1) + dp.at(j).at(k2) + 1;
          memo.at(mx).at(1) = {0, i, k1, j, k2};
        }
      }
      int mul = i * j;
      if (mul > n) continue;
      rep(k1, 2) rep(k2, 2) {
        int cost = dp.at(i).at(k1) + dp.at(j).at(k2) + 1;
        if (k1 == 1) cost += 2;
        if (k2 == 1) cost += 2;
        if (dp.at(mul).at(0) > cost) {
          dp.at(mul).at(0) = cost;
          memo.at(mul).at(0) = {1, i, k1, j, k2};
        }
      }
    }
  }
  cerr << dp.back().front() << " " << dp.back().back() << endl;
  string ans;
  auto rc = [&](const auto &self, int now, int nowt) -> void {
    auto [mode, l1, l2, r1, r2] = memo.at(now).at(nowt);
    // cerr << mode << " " << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
    if (mode == 2) {
      ans += string(l1, '1');
      return;
    }
    if (mode == 0) {
      self(self, l1, l2);
      ans.push_back('+');
      self(self, r1, r2);
      return;
    }
    if (l2 == 1) ans.push_back('(');
    self(self, l1, l2);
    if (l2 == 1) ans.push_back(')');
    ans.push_back('*');
    if (r2 == 1) ans.push_back('(');
    self(self, r1, r2);
    if (r2 == 1) ans.push_back(')');
  };
  if (dp.back().front() < dp.back().back())
    rc(rc, n, 0);
  else
    rc(rc, n, 1);
  cout << ans << endl;
  return 0;
}