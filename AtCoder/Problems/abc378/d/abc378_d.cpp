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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s.at(i);
  vector table(h, vector<bool>(w, false));
  int ans = 0;
  int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1};
  auto rc = [&](const auto &self, int i, int j, int co) -> void {
    if (s.at(i).at(j) == '#' || table.at(i).at(j)) return;
    table.at(i).at(j) = true;
    if (co == k) {
      table.at(i).at(j) = false;
      ans++;
      return;
    }
    rep(k, 4) {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
      self(self, ni, nj, co + 1);
    }
    table.at(i).at(j) = false;
  };
  rep(i, h) rep(j, w) rc(rc, i, j, 0);
  cout << ans << endl;
  return 0;
}