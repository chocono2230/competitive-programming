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
  int h, w, d;
  cin >> h >> w >> d;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  int ans = 0;
  vector<pair<int, int>> idxs;
  rep(i, h) rep(j, w) idxs.push_back({i, j});
  vector<pair<int, int>> v;
  auto rc = [&](const auto &self, int idx, int lv) -> void {
    if (lv == 2) {
      auto [pi, pj] = v.at(0);
      auto [qi, qj] = v.at(1);
      int res = 0;
      rep(i, h) rep(j, w) {
        if (s.at(i).at(j) == '.') {
          if (abs(pi - i) + abs(pj - j) <= d ||
              abs(qi - i) + abs(qj - j) <= d) {
            res++;
          }
        }
      }
      ans = max(ans, res);
      return;
    }
    if (idx == idxs.size()) return;
    auto [i, j] = idxs.at(idx);
    if (s.at(i).at(j) == '.') {
      v.push_back({i, j});
      self(self, idx + 1, lv + 1);
      v.pop_back();
    }
    self(self, idx + 1, lv);
  };
  rc(rc, 0, 0);
  cout << ans << endl;
  return 0;
}